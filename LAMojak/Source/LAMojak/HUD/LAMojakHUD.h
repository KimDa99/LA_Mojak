// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ULAMojakUIManager.h"
#include "LAMojakHUD.generated.h"

/**
 * 
 */
UCLASS()
class LAMOJAK_API ALAMojakHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ULAMojakUIManager* UIManager;

	//TSharedPtr<class SMainBoard> MainBoardWidget;
	//TSharedPtr<class SWidget> MainWidgetContainer;

};
