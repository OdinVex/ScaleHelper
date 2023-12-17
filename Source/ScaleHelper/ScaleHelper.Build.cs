// Copyright 2017-2023 Odin Vex. All Rights Reserved.

using UnrealBuildTool;

public class ScaleHelper : ModuleRules
{
	public ScaleHelper(ReadOnlyTargetRules Target) : base(Target)
	{
		
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "UnrealEd",
			}
			);
        
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "TargetPlatform",
            }
            );

        // Force IWYU compiling to avoid strange compilation issues related to having to include the same PCH first.
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    }
}
