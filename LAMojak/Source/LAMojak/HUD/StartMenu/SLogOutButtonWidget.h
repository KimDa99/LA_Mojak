// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

class LAMOJAK_API SLogOutButtonWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLogOutButtonWidget) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	const FString IconName = "SelectServer-logout-box.SelectServer-logout-box";
	const FString BrushAssetName = "BasicButtonBrush.BasicButtonBrush";
	const FVector2D IconSize = FVector2D(100.f, 100.f);
};
