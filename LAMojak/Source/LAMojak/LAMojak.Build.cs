// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LAMojak : ModuleRules
{
	public LAMojak(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

    }
}
