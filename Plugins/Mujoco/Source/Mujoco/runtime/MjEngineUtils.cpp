// Fill out your copyright notice in the Description page of Project Settings.


#include "MjEngineUtils.h"

#include <mujoco.h>

#include "XmlNode.h"
bool UMjEngineUtils::bAnglesInDegrees = true;
double* UMjEngineUtils::MjQuat = new double[4];
double* UMjEngineUtils::MjMat = new double[9];
FVector UMjEngineUtils::UnrealVector3(float* Coords, int EntryIndex)
{
	int StartOffset = EntryIndex * ElementsPerPosition;
	return FVector(-Coords[EntryIndex], Coords[EntryIndex + 1], Coords[EntryIndex + 2]);
}

void UMjEngineUtils::ParseTransformMjcf(FXmlNode* Mjcf, FTransform& Transform)
{
    // FVector FromPoint, ToPoint;
    // if (ParseFromToMjcf(Mjcf, FromPoint, ToPoint)) {
    //     Transform.SetLocation(FMath::Lerp(ToPoint, FromPoint, 0.5f));
    //     Transform.SetRotation(FQuat::FindBetweenNormals(FVector::UpVector, (ToPoint - FromPoint).GetSafeNormal()));
    // } else {
    //     // Parse the regular transform.
    //     Transform.SetLocation(UnrealVector3(Mjcf->GetVector3Attribute("pos", FVector::ZeroVector)));
    //     Transform.SetRotation(FQuat::Identity);
    //
    //     // Parse the rotation.
    //     if (Mjcf->HasAttribute("quat")) {
    //         Transform.SetRotation(UnityToUnrealQuat(Mjcf->GetQuaternionAttribute("quat", FQuat::Identity)));
    //     } else if (Mjcf->HasAttribute("zaxis")) {
    //         FVector UpAxis = UnrealVector3(Mjcf->GetVector3Attribute("zaxis", FVector::UpVector));
    //         Transform.SetRotation(FQuat::FindBetweenNormals(FVector::UpVector, UpAxis));
    //     } else if (Mjcf->HasAttribute("xyaxes")) {
    //         TArray<float> Xyaxes = Mjcf->GetFloatArrayAttribute("xyaxes", {1, 0, 0, 0, 1, 0});
    //         FVector XAxis = UnrealVector3(Xyaxes.GetData(), 0);
    //         FVector YAxis = UnrealVector3(Xyaxes.GetData(), 1);
    //         FVector ZAxis = FVector::CrossProduct(XAxis, YAxis);
    //         Transform.SetRotation(FQuat::FindBetweenNormals(FVector::UpVector, ZAxis));
    //     } else if (Mjcf->HasAttribute("axisangle")) {
    //         TArray<float> AxisAngle = Mjcf->GetFloatArrayAttribute("axisangle", {0, 0, 1, 0});
    //         FVector Axis = UnrealVector3(AxisAngle.GetData(), 0);
    //         float Angle = AxisAngle[3];
    //         if (bAnglesInDegrees == false) {
    //             Angle *= FMath::RadiansToDegrees(1);
    //         }
    //         Transform.SetRotation(FQuat(Axis, Angle));
    //     } else if (Mjcf->HasAttribute("euler")) {
    //         FVector Euler = UnrealVector3(Mjcf->GetVector3Attribute("euler", FVector::ZeroVector));
    //         if (bAnglesInDegrees == false) {
    //             Euler *= FMath::RadiansToDegrees(1);
    //         }
    //         Transform.SetRotation(FQuat::MakeFromEuler(Euler));
    //     }
    // }
}

bool UMjEngineUtils::ParseFromToMjcf(FXmlNode* Mjcf, FVector& FromPoint, FVector& ToPoint)
{
    // TArray<FXmlAttribute> Attributes=Mjcf->GetAttributes();
    // for (FXmlAttribute Attribute : Attributes) {
    //     if (Attribute.GetTag() == "fromto")
    //     {
    //         
    //     }
    // }
    // TArray<float> FromTo = Mjcf->GetFloatArrayAttribute("fromto", {});
    // if (FromTo.Num() >= 6) {
    //     FromPoint = UnrealVector3(FromTo.GetData(), 0);
    //     ToPoint = UnrealVector3(FromTo.GetData(), 1);
    //     FString NodeName = Mjcf->GetAttribute("name", Mjcf->GetTag());
    //     if ((ToPoint - FromPoint).Size() < FromToValidityTolerance) {
    //         UE_LOG(LogTemp, Warning, TEXT("%s: 'fromto' produces a vector that's too short. %s has magnitude %f lower than the tolerance %f"), *NodeName, *FromTo.ToString(), (ToPoint - FromPoint).Size(), FromToValidityTolerance);
    //         return false;
    //     }
    //     return true;
    // } else {
    //     FromPoint = FVector::ZeroVector;
    //     ToPoint = FVector::ZeroVector;
    //     return false;
    // }
	return false;
}

mjModel* UMjEngineUtils::LoadModelFromeFile(FString fileName)
{
	
	mjModel* m = mj_loadXML(TCHAR_TO_UTF8(*fileName), nullptr, nullptr, 0);
	if (m == nullptr) {
	    UE_LOG(LogTemp, Warning, TEXT("Failed to load model from file %s"), *fileName);
	}
	return m;
}
