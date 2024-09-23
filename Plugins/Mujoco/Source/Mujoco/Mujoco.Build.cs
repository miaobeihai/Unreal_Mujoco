// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class Mujoco : ModuleRules
{
	public Mujoco(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"XmlParser",
				"DesktopPlatform"
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"GeometricObjects", 
				"ProceduralMeshComponent", 
				"XmlParser",
				// ... add private dependencies that you statically link with here ...	
			}
		);

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
				
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
				"Mujoco/runtime",
				"Mujoco/runtime/Components",
				"Mujoco/runtime/Components/Bodies",
				"Mujoco/runtime/Components/Joints",
				"Mujoco/runtime/Components/Shapes",
				"Mujoco/runtime/Components/Tendons",
				"Mujoco/runtime/Components/Equality",
				"../ThirdParty/include/mujoco",
				"Mujoco/runtime/Components/Equality/Constraints",
				"Mujoco/MujocoImporter",
			}
		);


	


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
		Console.WriteLine("ModuleDirectory: " + ModuleDirectory);
		LoadMujoco();
	}

	public void LoadMujoco()
	{
		string ThridPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/"));
		Console.WriteLine("ThridPartyPath: " + ThridPartyPath);
		// Add the path to the Mujoco library
		PublicAdditionalLibraries.Add(Path.Combine(ThridPartyPath, "lib/mujoco.lib"));
		//string Dllstring = Path.Combine(ThridPartyPath, "dll/mujoco.dll");
		//PublicDelayLoadDLLs.Add(Dllstring);

		// Add the path to the Mujoco include directory
		PublicIncludePaths.Add(Path.Combine(ThridPartyPath, "include"));
	}

}
