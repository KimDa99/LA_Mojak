// Fill out your copyright notice in the Description page of Project Settings.

#include "../UResourceManager.h"
#include "SStartSettingButtonWidget.h"

void SStartSettingButtonWidget::Construct(const FArguments& InArgs)
{
	UTexture2D* IconImage = LoadObject<UTexture2D>(nullptr, *UResourceManager::Get()->GetTexturePath(IconName));

	FSlateBrush* IconBrush = new FSlateBrush();
	IconBrush->SetResourceObject(IconImage);
	IconBrush->SetImageSize(IconSize);

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, *UResourceManager::Get()->GetBrushAssetPath(BrushAssetName));

	ChildSlot
	[
		SNew(SButton)
		.ButtonStyle(ButtonStyle)
		[
			SNew(SImage)
			.Image(IconBrush)
		]
	];
}
