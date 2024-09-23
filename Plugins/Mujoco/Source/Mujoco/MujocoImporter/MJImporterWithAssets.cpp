#include "MJImporterWithAssets.h"

#include "MjEngineUtils.h"

AActor* MJImporterWithAssets::ImportFile(FString filePath)
{
	m=UMjEngineUtils::LoadModelFromeFile(filePath);
	if (m== nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load model from file %s"), *filePath);
		return nullptr;
	}
	return nullptr;
}
