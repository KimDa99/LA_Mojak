// Fill out your copyright notice in the Description page of Project Settings.

#include "SMainBoard.h"
#include "Widgets/Layout/SScaleBox.h"

#include "HUD/StartMenu/SServerSelectionWidget.h"
#include "HUD/StartMenu/SLogOutButtonWidget.h"
#include "HUD/StartMenu/SStartSettingButtonWidget.h"
#include "HUD/StartMenu/SStartMenuBackground.h"

void SMainBoard::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	ChildSlot
	[
		SAssignNew(ContentLay, SOverlay)
	];

}

void SMainBoard::AddWidget(TSharedRef<SWidget> Widget, const FMargin& Padding = FMargin(0.f), EHorizontalAlignment HAlign = EHorizontalAlignment::HAlign_Center, EVerticalAlignment VAlign = EVerticalAlignment::VAlign_Center)
{
	if (ContentLay.IsValid())
	{
		ContentLay->AddSlot()
			.Padding(Padding)
			.HAlign(HAlign) 
			.VAlign(VAlign)
			[
				SNew(SScaleBox)
					.Stretch(EStretch::ScaleToFit)
					[
					Widget
					]
			];
	}
}

void SMainBoard::RemoveWidget(TSharedRef<SWidget> Widget)
{
	if (ContentLay.IsValid())
	{
		ContentLay->RemoveSlot(Widget);
	}
}