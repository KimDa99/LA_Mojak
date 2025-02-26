// Fill out your copyright notice in the Description page of Project Settings.


#include "ULAMojakUIManager.h"
#include "Engine/Engine.h"
#include "Widgets/SWeakWidget.h"
#include "../SMainBoard.h"

void ULAMojakUIManager::Initialize(APlayerController* PlayerController, UResourceManager* InResourceManager, UTextManager* InTextManager)
{
	ResourceManager = InResourceManager;
	TextManager = InTextManager;

	if (GEngine && GEngine->GameViewport)
	{
		MainBoardWidget = SNew(SMainBoard);
		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(MainWidgetContainer, SWeakWidget).PossiblyNullContent(MainBoardWidget.ToSharedRef())
		);
	}
}

void ULAMojakUIManager::ShowMainBoard()
{
	if (GEngine && GEngine->GameViewport)
	{
		MainBoardWidget = SNew(SMainBoard);
		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(MainWidgetContainer, SWeakWidget).PossiblyNullContent(MainBoardWidget.ToSharedRef())
		);
	}
}

void ULAMojakUIManager::HideMainBoard()
{
	if (MainBoardWidget.IsValid())
	{
		MainBoardWidget->SetVisibility(EVisibility::Collapsed);
	}
}

void ULAMojakUIManager::ShowServerSelection()
{
	if (MainBoardWidget.IsValid())
	{
		StartMenuBackground = SNew(SStartMenuBackground);
		MainBoardWidget->AddWidget(StartMenuBackground.ToSharedRef(), 0.f, HAlign_Fill, VAlign_Fill);

		ServerSelectionWidget = SNew(SServerSelectionWidget);
		MainBoardWidget->AddWidget(ServerSelectionWidget.ToSharedRef(), 10.f, HAlign_Center, VAlign_Bottom);

		LogOutButtonWidget = SNew(SLogOutButtonWidget);
		MainBoardWidget->AddWidget(LogOutButtonWidget.ToSharedRef(), 10.f, HAlign_Right, VAlign_Bottom);

		StartSettingButtonWidget = SNew(SStartSettingButtonWidget);
		MainBoardWidget->AddWidget(StartSettingButtonWidget.ToSharedRef(), 10.f, HAlign_Left, VAlign_Bottom);
	}
}