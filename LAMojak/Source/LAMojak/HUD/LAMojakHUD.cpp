// Fill out your copyright notice in the Description page of Project Settings.

#include "LAMojakHUD.h"
#include "UResourceManager.h"
#include "TextManager.h"

#include "Engine/Engine.h"
#include "Widgets/SWeakWidget.h"
#include "../SMainBoard.h"

void ALAMojakHUD::BeginPlay()
{
	Super::BeginPlay();

    UTextManager* TextManager = UTextManager::Get();
    TextManager->InitializeLocalization();

    UResourceManager* ResourceManager = UResourceManager::Get();

	UIManager = NewObject<ULAMojakUIManager>();
	UIManager->Initialize(GetOwningPlayerController(), ResourceManager, TextManager);

	UIManager->ShowMainBoard();
	//UIManager->ShowServerSelection();

	UIManager->ShowInGameUI();
}
