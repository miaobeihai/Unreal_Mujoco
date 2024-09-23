// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
class MJImporterWithAssets;
class FSpawnTabArgs;
class FMujocoModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	FReply OnButtonClick();
	TSharedRef<SDockTab> CreateYourTab(const FSpawnTabArgs& Args);
	TSharedPtr<MJImporterWithAssets> Importer;
};
