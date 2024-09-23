// StlMeshParser.h
#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "StlMeshParser.generated.h"

UCLASS()
class MUJOCO_API UStlMeshParser : public UObject
{
	GENERATED_BODY()

public:
	UProceduralMeshComponent* ParseBinary(const TArray<uint8>& StlFileContents, FVector Scale);

	
	TArray<uint8> SerializeBinary(UProceduralMeshComponent* Mesh);
};

// StlMeshParser.cpp
