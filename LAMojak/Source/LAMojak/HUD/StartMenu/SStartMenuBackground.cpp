// Fill out your copyright notice in the Description page of Project Settings.


#include "SStartMenuBackground.h"

void SStartMenuBackground::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	UTexture2D* BackgroundTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/Images/StartMenu/LOSTARK_wallpaper_3840x2160_Limlake.LOSTARK_wallpaper_3840x2160_Limlake"));
	FSlateBrush* BackgroundImageBrush = new FSlateBrush();
	BackgroundImageBrush->SetResourceObject(BackgroundTexture);
	BackgroundImageBrush->SetImageSize(FVector2D(3840.f, 2160.f));

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
		];
}
