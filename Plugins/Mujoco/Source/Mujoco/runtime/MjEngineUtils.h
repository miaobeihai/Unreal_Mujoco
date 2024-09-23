// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <mjmodel.h>

#include "CoreMinimal.h"
#include "XmlNode.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MjEngineUtils.generated.h"

/**
 * 
 */
UCLASS()
class MUJOCO_API UMjEngineUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FVector UnrealVector3(float* Coords, int EntryIndex);
	static void ParseTransformMjcf(FXmlNode* Mjcf, FTransform& Transform);
	static bool ParseFromToMjcf(FXmlNode* Mjcf, FVector& FromPoint, FVector& ToPoint);

	static mjModel*  LoadModelFromeFile(FString fileName);

public:
	static bool bAnglesInDegrees;

private:
	static const int ElementsPerPosition = 3;
	static const int ElementsPerRotation = 4;
	static const int ElementsPerTransform = 7;
	static const int ElementsPerEquality = 11;
	static double* MjQuat;
	static double* MjMat ;
};
