// Fill out your copyright notice in the Description page of Project Settings.

#include "SImageTextButton.h"

#include "Widgets/Layout/SScaleBox.h"

void SImageTextButton::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	ChildSlot
	[
		SAssignNew(ButtonWidget, SButton)
		.ButtonStyle(InArgs._ButtonStyle)
		.OnClicked(InArgs._OnClicked)
		[
			SNew(SOverlay)

			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(ImageWidget, SImage)
				.Image(InArgs._ImageBrush)
			]

			+SOverlay::Slot()
			.Padding(InArgs._Padding)
			[
				SAssignNew(TextWidget, STextBlock)
				.Font(InArgs._FontInfo)
				.Text(InArgs._ButtonText)
			]
		]
	];
}

void SImageTextButton::SetText(const FText& Text)
{
	if (TextWidget.IsValid())
	{
		TextWidget->SetText(Text);
	}
}

void SImageTextButton::SetImage(UTexture2D* Texture)
{
	if (ImageWidget.IsValid())
	{
		// !!! Caution
		ImageWidget->SetImage(Texture);
	}
}