// StlMeshImporter.h
#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "StlMeshImporter.generated.h"

UCLASS()
class MUJOCO_API UStlMeshImporter : public UObject
{
	GENERATED_BODY()

public:
	UProceduralMeshComponent* OnImportAsset(FString AssetPath);
};