// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"
#include "ServerInfo.h"


class LAMOJAK_API SServerSelectionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SServerSelectionWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class ALAMojakHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TArray<FServerInfo> PlayersServerInfos;

	void GetServerInfo();

	virtual bool SupportsKeyboardFocus() const override { return true; }

	TSharedRef<SVerticalBox> GenerateServerTextButtons();

	TSharedPtr<SVerticalBox> VerticalBoxWidget;

};
