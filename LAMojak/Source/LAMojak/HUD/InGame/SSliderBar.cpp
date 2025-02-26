// Fill out your copyright notice in the Description page of Project Settings.


#include "SSliderBar.h"
#include "SlateOptMacros.h"
#include"../UResourceManager.h"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSliderBar::Construct(const FArguments& InArgs)
{
	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* OuterTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(OuterTextureName));
	UTexture2D* InnerTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(InnerTextureName));

	FSlateBrush* OuterImageBrush = new FSlateBrush();
	OuterImageBrush->SetResourceObject(OuterTexture);
	OuterImageBrush->SetImageSize(SliderBarSize);

	FSlateBrush* InnerImageBrush = new FSlateBrush();
	InnerImageBrush->SetResourceObject(InnerTexture);
	InnerImageBrush->SetImageSize(SliderBarSize);

	FSlateFontInfo Font = FSlateFontInfo(LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath(FontName)), 25);


	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(OuterImageBrush)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(SliderBox, SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(SliderValue)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
						.Image(InnerImageBrush)
					]
					+ SHorizontalBox::Slot()
					.FillWidth(1 - SliderValue)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
						.Image(OuterImageBrush)
					]
			]
		];
}

void SSliderBar::SetAndUpdateSliderValue(float NewValue)
{
	SliderValue = NewValue;

	if (SliderBox.IsValid())
	{
		SliderBox->GetSlot(0).SetFillWidth(SliderValue);
		SliderBox->GetSlot(1).SetFillWidth(1 - SliderValue);
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
