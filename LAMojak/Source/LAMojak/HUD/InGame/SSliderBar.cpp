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
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SAssignNew(CurrentValueText, STextBlock)
						.Font(Font)
						.Text(FText::FromString("1000"))
				]

				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(STextBlock)
					.Font(Font)
					.Text(FText::FromString("/"))
				]

				+SHorizontalBox::Slot()
				.AutoWidth()
				[
					SAssignNew(MaxValueText, STextBlock)
					.Font(Font)
					.Text(FText::FromString("1000"))
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
void SSliderBar::SetSliderImage(FString NewTexturePath)
{
	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(NewTexturePath));
	FSlateBrush* ImageBrush = new FSlateBrush();
	ImageBrush->SetResourceObject(Texture);
	ImageBrush->SetImageSize(SliderBarSize);

	if (SliderBox.IsValid())
	{
		TSharedPtr<SWidget> Widget = (SliderBox)->GetChildren()->GetChildAt(0);
		StaticCastSharedPtr<SImage>(Widget)->SetImage(ImageBrush);
	}
}
void SSliderBar::SetCurrentValueText(FString NewText)
{
}
void SSliderBar::SetMaxValueText(FString NewText)
{
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
