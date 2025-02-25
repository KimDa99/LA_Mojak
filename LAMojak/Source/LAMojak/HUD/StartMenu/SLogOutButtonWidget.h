// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

class LAMOJAK_API SLogOutButtonWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLogOutButtonWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class ALAMojakHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

};
