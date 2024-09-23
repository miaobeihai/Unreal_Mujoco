// Copyright Epic Games, Inc. All Rights Reserved.

#include "Mujoco/Public/Mujoco.h"
#include "MJImporterWithAssets.h"
#include "DesktopPlatformModule.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Docking/SDockTab.h"
#define LOCTEXT_NAMESPACE "FMujocoModule"

void FMujocoModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner("Mujoco", FOnSpawnTab::CreateRaw(this, &FMujocoModule::CreateYourTab));
			//.SetDisplayName(NSLOCTEXT("FMujocoModule", "TabTitle", "Mujoco"));
}

void FMujocoModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("YourTab");
}

FReply FMujocoModule::OnButtonClick()
{
		
		FString DefaultPath = FPaths::ProjectDir();
		FString FileTypes = TEXT("XML files (*.xml)|*.xml");
		TArray<FString> SelectedFileName;
		bool bOpened = FDesktopPlatformModule::Get()->OpenFileDialog(
			nullptr,
			TEXT("Select an MJCF model"),
			DefaultPath,
			TEXT(""),
			FileTypes,
			0,
			SelectedFileName
		);

		if (bOpened)
		{
			// Use SelectedFileName
			if (SelectedFileName.Num()>0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Name:%s"),*SelectedFileName[0]);
			}
			Importer=MakeShareable(new MJImporterWithAssets());
			if (Importer.IsValid())
			{
				Importer->ImportFile(SelectedFileName[0]);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to create importer"));
			}
			//only import the first file now
			
		}
		
		return FReply::Handled();
}


TSharedRef<SDockTab> FMujocoModule::CreateYourTab(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.MaxHeight(100)
			.Padding(10)
			[
				SNew(SButton)
				.Text(NSLOCTEXT("FMujocoModule", "ButtonText", "Import mujoco scene"))
				.OnClicked(FOnClicked::CreateRaw(this, &FMujocoModule::OnButtonClick))
			]
		];
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMujocoModule, Mujoco)