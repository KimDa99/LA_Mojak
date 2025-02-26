// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"
#include "ServerInfo.h"


class LAMOJAK_API SServerSelectionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SServerSelectionWidget) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	void GetServerInfo();

	TSharedRef<SVerticalBox> GenerateServerTextButtons();

	TArray<FServerInfo> PlayersServerInfos;
	TSharedPtr<SVerticalBox> VerticalBoxWidget;
};
