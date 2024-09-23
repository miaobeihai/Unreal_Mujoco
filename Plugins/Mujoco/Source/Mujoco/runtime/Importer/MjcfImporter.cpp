// MjcfImporter.cpp
#include "MjcfImporter.h"

#include "MjActuator.h"
#include "MjBallJoint.h"
#include "MjBody.h"
#include "MjEngineUtils.h"
#include "MjExclude.h"
#include "MjFreeJoint.h"
#include "MjGlobalSettings.h"
#include "MjHingeJoint.h"
#include "MjJointConstraint.h"
#include "MjSite.h"
#include "MjSlideJoint.h"
#include "MjWeld.h"
#include "XmlFile.h"
#include "Components/MjInertial.h"
#include "Equality/MjConnect.h"
#include "Tendons/MjFixedTendon.h"
#include "Tendons/MjSpatialTendon.h"


UMjcfImporter::UMjcfImporter()
{
	// Initialize properties
	DefaultMujocoMaterial = CreateDefaultSubobject<UMaterial>(TEXT("DefaultMujocoMaterial"));
	// ... other initializations ...
}



AActor* UMjcfImporter::ImportString(FString mjcfString, FString name)
{
	FXmlFile mjcfXml(*mjcfString);
	return ImportXml(&mjcfXml, name);
}

AActor* UMjcfImporter::ImportXml(FXmlFile* XmlFile, const FString& Name)
{
	// Reset the numbering of anonymous nodes to ensure deterministic naming of loaded scenes.
	_NumGeneratedNames = 0;

	Modifiers = MakeShared<FMjXmlModifiers>(XmlFile);

	//todo 
	//Modifiers->Configure(MjcfXml);

	ConfigureAngleType(XmlFile);

	// We're adopting the approach of building the scene hierarchy as we parse the Mjcf.
	// Should we encounter any error, we'll terminate and clean it immediately.
	// Having a single root object for that will be very helpful, since we only need to delete that
	// object.
	//UObject* SceneRoot = NewObject<UObject>(this, UObject::StaticClass(), *Name);

	AActor * SceneRoot = NewObject<AActor>(this, *Name);

	// We'll use Exceptions as a way to communicate errors encountered during parsing.
	try {
		ParseRoot(SceneRoot, XmlFile->GetRootNode());
	} catch (const std::exception& Ex) {
		// We consider any error as critical, and end the import process immediately, cleaning up
		// what we have already built.
		UE_LOG(LogTemp, Warning, TEXT("Exception: %s"), *FString(Ex.what()));
		SceneRoot->ConditionalBeginDestroy();
		Modifiers = nullptr;
		throw;
	} 

	return SceneRoot;
}


void UMjcfImporter::ConfigureAngleType(FXmlFile* MjcfXml)
{
	FXmlNode* CompilerNode = MjcfXml->GetRootNode()->FindChildNode("compiler");
	if (CompilerNode != nullptr) {
		// Parse the angle type.
		FString AngleSetting = CompilerNode->GetAttribute("angle");
		if (AngleSetting.IsEmpty()) {
			AngleSetting = _AngleTypeDegree;
		}
		UMjEngineUtils::bAnglesInDegrees = (AngleSetting == _AngleTypeDegree);
	}
}

USceneComponent* UMjcfImporter::CreateCompomentInParent(FString Str, AActor* ParentObject)
{
	USceneComponent* Component = NewObject<USceneComponent>(ParentObject, *Str);
	Component->SetupAttachment(ParentObject->GetRootComponent());
	return Component;
}

void UMjcfImporter::ParseBodyChildren(AActor* Actor, FXmlNode* XmlNode)
{
	for (const auto& Child : XmlNode->GetChildrenNodes()) {
		Modifiers->ApplyModifiersToElement(Child);
		ParseBodyChild(Actor, Child);
	}
}

void UMjcfImporter::ParseBodyChild(AActor* Actor, FXmlNode* XmlNode)
{
	FString ChildName = XmlNode->GetTag();

	if (ChildName == "geom") {
		ParseGeom(Actor, XmlNode);
	} else if (ChildName == "inertial") {
		CreateComponentWithUniqueName<UMjInertial>(Actor->GetRootComponent(), XmlNode);
	} else if (ChildName == "body") {
		CreateComponentWithUniqueName<UMjBody>(Actor->GetRootComponent(), XmlNode);
		ParseBodyChildren(Actor, XmlNode);
	} else if (ChildName == "joint") {
		ParseJointType(Actor, XmlNode);
	} else if (ChildName == "freejoint") {
		CreateComponentWithUniqueName<UMjFreeJoint>(Actor->GetRootComponent(), XmlNode);
	} else if (ChildName == "site") {
		CreateComponentWithUniqueName<UMjSite>(Actor->GetRootComponent(), XmlNode);
	} else if (ChildName == "camera") {
		//use UE4  camera
		//CreateObjectWithCamera(ParentObject, Child);
	} else {
		UE_LOG(LogTemp, Log, TEXT("The importer does not yet support tags <%s>."), *ChildName);
	}
}

void UMjcfImporter::ParseRoot(AActor* RootObject, FXmlNode* MujocoNode)
{
    if (MujocoNode->FindChildNode("option") != nullptr
        || MujocoNode->FindChildNode("size") != nullptr
        || MujocoNode->FindChildNode("custom") != nullptr) {
        UMjGlobalSettings* SettingsComponent = NewObject<UMjGlobalSettings>();
    	SettingsComponent->AttachToComponent(RootObject->GetRootComponent(),FAttachmentTransformRules::KeepWorldTransform);

    	//TODO 
        //SettingsComponent->ParseGlobalMjcfSections(MujocoNode);
    }

    // This makes references to assets.
    FXmlNode* WorldBodyNode = MujocoNode->FindChildNode("worldbody");
    ParseBodyChildren(RootObject, WorldBodyNode);

    // This section references bodies, must be parsed after worldbody.
    FXmlNode* ExcludeNode = MujocoNode->FindChildNode("contact");
    if (ExcludeNode != nullptr) {
    	// test :create UE4 Component is ok?
        USceneComponent* ExcludesParentObject = CreateSceneComponent(RootObject,"excludes");
        for (const auto& Child : ExcludeNode->GetChildrenNodes()) {
            if (Child->GetTag() != "exclude") {
                UE_LOG(LogTemp, Warning, TEXT("Only 'exclude' is supported - %s isn't supported yet."), *Child->GetTag());
            } else {
                Modifiers->ApplyModifiersToElement(Child);
                CreateComponentWithUniqueName<UMjExclude>(ExcludesParentObject, Child);
            }
        }
    }

    // This section references joints/sites/geoms, must be parsed after worldbody.
    FXmlNode* TendonNode = MujocoNode->FindChildNode("tendon");
    if (TendonNode != nullptr) {
        USceneComponent* TendonsParentObject = CreateSceneComponent(RootObject,"tendons");
        for (const auto& Child : TendonNode->GetChildrenNodes()) {
            Modifiers->ApplyModifiersToElement(Child, "tendon");
            if (Child->GetTag() == "fixed") {
                CreateComponentWithUniqueName<UMjFixedTendon>(TendonsParentObject, Child);
            } else if (Child->GetTag() == "spatial") {
                CreateComponentWithUniqueName<UMjSpatialTendon>(TendonsParentObject, Child);
            } else {
                UE_LOG(LogTemp, Log, TEXT("Tendon type %s not supported."), *Child->GetTag());
            }
        }
    }

    // This section references worldbody elements + tendons, must be parsed after them.
    FXmlNode* EqualityNode = MujocoNode->FindChildNode("equality");
    if (EqualityNode != nullptr) {
        USceneComponent* EqualitiesParentObject = CreateSceneComponent(RootObject,TEXT("equality_constraints"));
        for (const auto& Child : EqualityNode->GetChildrenNodes()) {
            ParseEqualityType(EqualitiesParentObject,Child);
            Modifiers->ApplyModifiersToElement(Child);
        }
    }

    // This section references joints and tendons, must be parsed after worldbody and tendon.
    FXmlNode* ActuatorNode = MujocoNode->FindChildNode("actuator");
    if (ActuatorNode != nullptr) {
        USceneComponent* ActuatorsParentObject = CreateSceneComponent(RootObject,"actuators");
        for (const auto& Child : ActuatorNode->GetChildrenNodes()) {
            Modifiers->ApplyModifiersToElement(Child);
            CreateComponentWithUniqueName<UMjActuator>(ActuatorsParentObject, Child);
        }
    }

	 /*
	  * we do not need to parse sensor,use UE4 sensor replace
	  */
    // This section references tendons, actuators and worldbody elements, must be parsed last.
    // FXmlNode* SensorNode = MujocoNode->FindChildNode("sensor");
    // if (SensorNode != nullptr) {
    //     UObject* SensorParentObject = CreateObjectInParent("sensors", RootObject);
    //     for (const auto& Child : SensorNode->GetChildrenNodes()) {
    //         Modifiers->ApplyModifiersToElement(Child);
    //         FString SensorType = ParseSensorType(Child);
    //         if (!SensorType.IsEmpty()) {
    //             CreateObjectWithUniqueName(SensorParentObject, Child, SensorType);
    //         }
    //     }
    // }
}

void UMjcfImporter::ParseGeom(AActor* ParentObject, FXmlNode* XmlNode)
{
}

void UMjcfImporter::ParseJointType(AActor* ParentObject, FXmlNode* Child)
{
	FString TypeString = Child->GetAttribute(TEXT("type"));
		
	if (TypeString == "hinge")
	{
		CreateComponentWithUniqueName<UMjHingeJoint>(ParentObject->GetRootComponent(), Child);
	}
	else if (TypeString == "ball")
	{
		CreateComponentWithUniqueName<UMjBallJoint>(ParentObject->GetRootComponent(), Child);
			
	}
	else if (TypeString == "slide")
	{
		CreateComponentWithUniqueName<UMjSlideJoint>(ParentObject->GetRootComponent(), Child);
	}
	else if (TypeString == "free")
	{
			
		CreateComponentWithUniqueName<UMjFreeJoint>(ParentObject->GetRootComponent(), Child);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unsupported Joint type: %s"), *TypeString);
	}
	// According to http://mujoco.org/book/XMLreference.html#joint, the default type for a joint is Hinge.

	return ;
}

void UMjcfImporter::ParseEqualityType(USceneComponent* ParentObject, FXmlNode* Child)
{
	FString TypeString = Child->GetAttribute(TEXT("type"));
	if (TypeString == "connect")
	{
		CreateComponentWithUniqueName<UMjConnect>(ParentObject, Child);
	}
	else if (TypeString == "weld")
	{
		CreateComponentWithUniqueName<UMjWeld>(ParentObject, Child);
			
	}
	else if (TypeString == "joint")
	{
		CreateComponentWithUniqueName<UMjJointConstraint>(ParentObject, Child);
	}
	else if (TypeString == "tendon")
	{
		//CreateComponentWithUniqueName<UMjTendon>(ParentObject, Child);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unsupported equality type: %s"), *TypeString);
	}
}

USceneComponent* UMjcfImporter::CreateSceneComponent(AActor* ParentObject, FString ComponentName)
{
	USceneComponent* Component = NewObject<USceneComponent>(ParentObject, FName(*ComponentName));
	Component->SetupAttachment(ParentObject->GetRootComponent());
	return Component;
}


// ... other method implementations ...
