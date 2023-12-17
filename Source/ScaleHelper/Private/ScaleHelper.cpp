#include "ScaleHelper.h"
#include "UObject/Class.h"
#include "UObject/UObjectGlobals.h"
#include "Misc/MessageDialog.h"
#include "ScaleHelperTypes.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#define LOCTEXT_NAMESPACE "FScaleHelperModule"

void FScaleHelperModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		TSharedPtr<ISettingsSection> PluginSettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "ScaleHelper",
		LOCTEXT("PluginRuntimeSettingsName", "ScaleHelper"),
		LOCTEXT("PluginRuntimeSettingsDescription", "ScaleHelper Plugin Settings."),
		GetMutableDefault<UScaleHelper_PluginSettings>());

		if (GetMutableDefault<UScaleHelper_PluginSettings>()->fEditorScale)
		{
			UE_LOG(LogTemp, Warning, TEXT("EditorScale"));
			UOnlineSubsystemConfiguratorBPLibrarySettings *subsystemSettings = GetMutableDefault<UOnlineSubsystemConfiguratorBPLibrarySettings>();
			FString ProjectVersion;
			GConfig->GetString(
				TEXT("/Script/EngineSettings.GeneralProjectSettings"),
				TEXT("ProjectVersion"),
				OUT ProjectVersion,
				GGameIni
			);
			GConfig->SetString(TEXT("OnlineSubsystemSteam"), TEXT("GameVersion"), *subsystemSettings->GameVersion, DefaultEngineIniPath);
				GConfig->Flush(false, DefaultEngineIniPath);
		}
	}
	FSlateApplication::Get().SetApplicationScale(this->EditorScale);
}

void FScaleHelperModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ScaleHelper");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FScaleHelperModule, ScaleHelper)