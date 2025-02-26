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

	const FVector2D ButtonSize = FVector2D(256.f, 64.f);
	const FString OddButtonTextureName = "insideBorder_0.insideBorder_0";
	const FString EvenButtonTextureName = "insideBorder_1.insideBorder_1";
	const FString ButtonStyleName = "BasicButtonBrush.BasicButtonBrush";
	const FString TitleFontName = "Danjo-bold-Regular_Font.Danjo-bold-Regular_Font";
	const FString ContentsFontName = "GowunDodum-Regular_Font.GowunDodum-Regular_Font";
};
