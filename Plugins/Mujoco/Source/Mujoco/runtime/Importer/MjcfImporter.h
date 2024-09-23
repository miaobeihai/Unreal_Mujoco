// MjcfImporter.h
#pragma once

#include "CoreMinimal.h"
#include "MjXmlModifiers.h"
#include "XmlFile.h"
#include "MjcfImporter.generated.h"

UCLASS()
class MUJOCO_API UMjcfImporter : public UObject
{
	GENERATED_BODY()

public:
	UMjcfImporter();

	AActor* ImportXml(FXmlFile* XmlFile, const FString& Name);

	AActor* ImportString(FString mjcfString, FString name = TEXT("default"));
	void ConfigureAngleType(FXmlFile* MjcfXml);
	USceneComponent* CreateCompomentInParent(FString Str, AActor* Object);
	void ParseBodyChildren(AActor* Actor, FXmlNode* XmlNode);
	void ParseBodyChild(AActor* Actor, FXmlNode* XmlNode);
	
	void ParseRoot(AActor* RootObject, FXmlNode* MujocoNode);
	
    void ParseGeom(AActor* ParentObject, FXmlNode* XmlNode);

	void  ParseJointType(AActor* ParentObject, FXmlNode* Child);

	void ParseEqualityType(USceneComponent* ParentObject, FXmlNode* Child);

	USceneComponent* CreateSceneComponent(AActor* ParentObject, FString ComponentName);

	/*
	template<typename T>
	T* CreateComponentWithUniqueName(AActor* ParentObject, FXmlNode* XmlNode)
	{
		return CreateComponentWithUniqueName(ParentObject->GetRootComponent(),XmlNode);
	}*/

	template<typename T>
	T* CreateComponentWithUniqueName(USceneComponent* ParentObject, FXmlNode* XmlNode)
	{
		auto name = XmlNode->GetTag();
		auto component = NewObject<T>(ParentObject, *name);
		component->AttachToComponent(ParentObject,FAttachmentTransformRules::KeepWorldTransform);
		// TODO 
		//component->ParseMjcf(XmlNode);
		return component;
	}
	


	// ... other methods and properties ...

private:
	

private:
	UPROPERTY()
	UMaterial* DefaultMujocoMaterial;

	TSharedPtr<FMjXmlModifiers>  Modifiers;

	
	int _NumGeneratedNames;

	FString _AngleTypeDegree="degree";

	// ... other methods and properties ...
};


