#pragma once
#include <mjmodel.h>

class MJImporterWithAssets
{
public:
	AActor * ImportFile(FString filePath);

private:
	mjModel* m;
};
