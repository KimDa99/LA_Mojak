// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// StartMenu
#include "StartMenu/SServerSelectionWidget.h"
#include "StartMenu/SLogOutButtonWidget.h"
#include "StartMenu/SStartMenuBackground.h"
#include "StartMenu/SStartSettingButtonWidget.h"

// InGame
#include "InGame/SSliderBar.h"
#include "InGame/SItemSkillBox.h"

#include "Widgets/SCompoundWidget.h"
#include "UResourceManager.h"
#include "TextManager.h"
#include "ULAMojakUIManager.generated.h"

/**
 * 
 */
UCLASS()
class LAMOJAK_API ULAMojakUIManager : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(APlayerController* PlayerController, UResourceManager* InResourceManager, UTextManager* InTextManager);
	void ShowMainBoard();
	void HideMainBoard();

private:
	UResourceManager* ResourceManager;
	UTextManager* TextManager;

	TSharedPtr<class SMainBoard> MainBoardWidget;
	TSharedPtr<SWidget> MainWidgetContainer;

public:
	void ShowServerSelection();

private:
	TSharedPtr<SStartMenuBackground> StartMenuBackground;
	TSharedPtr<SServerSelectionWidget> ServerSelectionWidget;
	TSharedPtr<SLogOutButtonWidget> LogOutButtonWidget;
	TSharedPtr<SStartSettingButtonWidget> StartSettingButtonWidget;

private:
	TSharedPtr<SSliderBar> SliderBarWidget;
	TSharedPtr<SItemSkillBox> ItemSkillBoxWidget;
public:
	void ShowInGameUI();

};
