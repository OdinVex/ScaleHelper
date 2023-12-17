#pragma once

#include "CoreMinimal.h"
#include "ScaleHelper.h"
#include "ScaleHelperTypes.generated.h"

UCLASS(config = Engine, defaultconfig)
class UOnlineScaleHelperBPLibrarySettings : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, config, Category = ScaleHelperSettings, meta = (ToolTip="Sets the initial editor scale (whole editor).", ConfigRestartRequired = true))
        float EditorScale = StaticHelper::EditorScale;

#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

};