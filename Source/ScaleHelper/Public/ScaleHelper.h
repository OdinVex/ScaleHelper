#pragma once

#include "Modules/ModuleManager.h"

class FScaleHelperModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	float EditorScale = 1.0;
};
