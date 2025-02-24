// Fill out your copyright notice in the Description page of Project Settings.

#include "LAMojakHUD.h"

#include "Engine/Engine.h"
#include "Widgets/SWeakWidget.h"
#include "../SMainBoard.h"

void ALAMojakHUD::BeginPlay()
{
	if (GEngine && GEngine->GameViewport)
	{
		MainBoardWidget = SNew(SMainBoard).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(MainWidgetContainer, SWeakWidget).PossiblyNullContent(MainBoardWidget.ToSharedRef()));
	}
}
