#include "StlMeshParser.h"


UProceduralMeshComponent* UStlMeshParser::ParseBinary(const TArray<uint8>& StlFileContents, FVector Scale)
{
	FMemoryReader Reader(StlFileContents, true);
	Reader.Seek(80); // Skip header

	uint32 NumTriangles;
	Reader << NumTriangles;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;

	for (uint32 i = 0; i < NumTriangles; ++i)
	{
		FVector Normal;
		Reader << Normal;

		for (int j = 0; j < 3; ++j)
		{
			FVector Vertex;
			Reader << Vertex;
			Vertices.Add(Vertex * Scale);
			Triangles.Add(Vertices.Num() - 1);
		}

		uint16 AttributeByteCount;
		Reader << AttributeByteCount;
	}

	UProceduralMeshComponent* Mesh = NewObject<UProceduralMeshComponent>();
	Mesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(), true);

	return Mesh;
}


// TArray<uint8> UStlMeshParser::SerializeBinary(UProceduralMeshComponent* Mesh)
// {
// 	TArray<uint8> StlFileContents;
// 	FMemoryWriter Writer(StlFileContents, true);
//
// 	// Write header
// 	Writer << FString("solid");
//
// 	// Write number of triangles
// 	uint32 NumTriangles = Mesh->GetNumSections();
// 	Writer << NumTriangles;
//
// 	for (uint32 i = 0; i < NumTriangles; ++i)
// 	{
// 		// Write normal
// 		FVector Normal;
// 		Mesh->GetSectionNormal(i, Normal);
// 		Writer << Normal;
//
// 		// Write vertices
// 		TArray<FVector> Vertices;
// 		Mesh->GetSectionVertices(i, Vertices);
// 		for (int j = 0; j < 3; ++j)
// 		{
// 			Writer << Vertices[j];
// 		}
//
// 		// Write attribute byte count
// 		uint16 AttributeByteCount = 0;
// 		Writer << AttributeByteCount;
// 	}
//
// 	return StlFileContents;
// }