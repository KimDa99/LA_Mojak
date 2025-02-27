// Fill out your copyright notice in the Description page of Project Settings.

#include "SBottomRightButton.h"
#include "../UResourceManager.h"
#include "../TextManager.h"

void SBottomRightButton::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* PanelTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath("InGame-shopping"));

	FSlateBrush* PanelImageBrush = new FSlateBrush();
	PanelImageBrush->SetResourceObject(PanelTexture);
	PanelImageBrush->SetImageSize(FVector2D(PanelTexture->GetSizeX() * 2.f, PanelTexture->GetSizeY() * 2.f));

	FSlateFontInfo TextStyle(LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath("Danjo-bold-Regular_Font")), 15);

	FText BottomText = UTextManager::Get()->GetLocalizedText("InGame-BottomRight-Shop");

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, *ResourceManager->GetBrushAssetPath("BasicButtonBrush"));

	ChildSlot
		[
			SNew(SOverlay)

				+ SOverlay::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
				[
					SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(InArgs._Padding)
						[
							SNew(SImage)
								.Image(InArgs._ImageBrush)
						]

						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(InArgs._Padding)
						[
							SNew(STextBlock)
								.Text(InArgs._ButtonText)
								.Font(InArgs._FontInfo)
								.ColorAndOpacity(InArgs._Color)
						]
				]

				+ SOverlay::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
				[
					SNew(SButton)
						.ButtonStyle(InArgs._ButtonStyle)
						.OnClicked(InArgs._OnClicked)
				]

		];
}