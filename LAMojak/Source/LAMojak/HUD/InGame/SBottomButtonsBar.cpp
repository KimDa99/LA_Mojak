// Fill out your copyright notice in the Description page of Project Settings.

#include "SBottomButtonsBar.h"
#include "../UResourceManager.h"

void SBottomButtonsBar::Construct(const FArguments& InArgs)
{
    bCanSupportFocus = true;

	ChildSlot
		[
		//	SAssignNew(Container, SHorizontalBox)
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SButton)
				]
		];

	//CreateButton(ShopTextureName, LOCTEXT("Shop", "상점"));
//		FOnClicked::CreateSP(this, &SBottomButtonsBar::OnDefaultButtonClicked));
}

//void SBottomButtonsBar::CreateButton(FString TexturePath, FText ButtonText)//, FOnClicked ButtonClicked)
//{
//	UResourceManager* ResourceManager = UResourceManager::Get();
//	UTexture2D* ButtonTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(TexturePath));
//	FSlateBrush* ButtonImageBrush = new FSlateBrush();
//	ButtonImageBrush->SetResourceObject(ButtonTexture);
//	ButtonImageBrush->SetImageSize(FVector2D(ButtonTexture->GetSizeX(), ButtonTexture->GetSizeY()));
//
//	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, *ResourceManager->GetBrushAssetPath("BasicButtonBrush"));
//
//	Container->AddSlot()
//		.AutoWidth()
//		.Padding(5.0f)
//		[
//			SNew(SButton)
//			.ButtonStyle(ButtonStyle)
//			.HAlign(HAlign_Fill)
//		    [
//
//				SNew(SOverlay)
//				+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Top).Padding(5.0f)
//				[
//					SNew(SImage)
//					.Image(ButtonImageBrush)
//				]
//
//				+ SOverlay::Slot().HAlign(HAlign_Center).VAlign(VAlign_Bottom).Padding(5.0f)
//				[
//					SNew(STextBlock)
//					.Text(ButtonText)
//				]
//			]
//        ];
//
//	delete ButtonImageBrush;
//}
//
////FReply SBottomButtonsBar::OnDefaultButtonClicked()
////{
////    return FReply::Handled();
////}
