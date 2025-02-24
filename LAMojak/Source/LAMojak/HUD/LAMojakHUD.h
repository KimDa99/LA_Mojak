// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LAMojakHUD.generated.h"

/**
 * 
 */
UCLASS()
class LAMOJAK_API ALAMojakHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	TSharedPtr<class SMainBoard> MainBoardWidget;
	TSharedPtr<class SWidget> MainWidgetContainer;

	virtual void BeginPlay() override;
};
