// Fill out your copyright notice in the Description page of Project Settings.

#include "SMainBoard.h"
#include "Widgets/Layout/SScaleBox.h"

#include "HUD/StartMenu/SServerSelectionWidget.h"
#include "HUD/StartMenu/SLogOutButtonWidget.h"
#include "HUD/StartMenu/SStartSettingButtonWidget.h"

void SMainBoard::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	UTexture2D* BackgroundTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/MainBoardImage.MainBoardImage"));
	FSlateBrush* BackgroundImageBrush = new FSlateBrush();
	BackgroundImageBrush->SetResourceObject(BackgroundTexture);
	BackgroundImageBrush->SetImageSize(FVector2D(256.f, 256.f));

	UObject* TitleFont;
	TitleFont = LoadObject<UObject>(nullptr, TEXT("/Game/Resources/Fonts/Danjo-bold-Regular_Font.Danjo-bold-Regular_Font"));
	FSlateFontInfo TitleStyleText = FSlateFontInfo(TitleFont, 60);

	UObject* ContentsFont;
	ContentsFont = LoadObject<UObject>(nullptr, TEXT("/Game/Resources/Fonts/GowunDodum-Regular_Font.GowunDodum-Regular_Font"));
	FSlateFontInfo ContentsStyleText = FSlateFontInfo(ContentsFont, 30);

	FMargin TitlePadidng(10.f);

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(BackgroundImageBrush)
		]

		+SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(TitlePadidng)
		[
			SNew(SScaleBox)
			.Stretch(EStretch::ScaleToFit)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				[
					SAssignNew(TitleTextWidget, STextBlock)
					.Text(FText::FromString("None"))
					.Font(TitleStyleText)
					.ColorAndOpacity(FColor::Black)
				]

				+SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				[
					SAssignNew(ContentsTextWidget, STextBlock)
					.Text(FText::FromString("None"))
					.Font(ContentsStyleText)
					.ColorAndOpacity(FColor::Black)
				]
			]

		]

		// For Test: start Menu
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Bottom)
		[
			SNew(SScaleBox)
			.Stretch(EStretch::ScaleToFit)
			[
				SNew(SServerSelectionWidget)
			]
		]

		// LogOut
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		.Padding(20.f)
		[
			SNew(SScaleBox)
			.Stretch(EStretch::ScaleToFit)
			[
				SNew(SLogOutButtonWidget)
			]
		]

		// Setting
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		.Padding(20.f)
		[
			SNew(SScaleBox)
			.Stretch(EStretch::ScaleToFit)
			[
				SNew(SStartSettingButtonWidget)
			]
		]

	];
}

void SMainBoard::SetTitleText(FText NewText)
{
	if (TitleTextWidget.IsValid())
	{
		TitleTextWidget->SetText(NewText);
	}
}

void SMainBoard::SetContentsText(FText NewText)
{
	if (ContentsTextWidget.IsValid())
	{
		ContentsTextWidget->SetText(NewText);
	}
}
