// // StlMeshImporter.cpp
// #include "StlMeshImporter.h"
// #include "StlMeshParser.h"
// #include "ProceduralMeshComponent.h"
// #include "Misc/FileHelper.h"
//
// UProceduralMeshComponent* UStlMeshImporter::OnImportAsset(FString AssetPath)
// {
// 	TArray<uint8> ModelContents;
// 	if (!FFileHelper::LoadFileToArray(ModelContents, *AssetPath))
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("Failed to load file: %s"), *AssetPath);
// 		return nullptr;
// 	}
//
// 	UProceduralMeshComponent* Mesh = UStlMeshParser::ParseBinary(ModelContents, FVector(1.0f, 1.0f, 1.0f));
//
// 	return Mesh;
// }