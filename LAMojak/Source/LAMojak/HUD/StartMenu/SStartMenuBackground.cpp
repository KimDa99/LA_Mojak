// Fill out your copyright notice in the Description page of Project Settings.


#include "SStartMenuBackground.h"
#include "../UResourceManager.h"

void SStartMenuBackground::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* BackgroundTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath("ServerSelect-Background"));
	BackgroundTexture->GetSizeX();
	FSlateBrush* BackgroundImageBrush = new FSlateBrush();
	BackgroundImageBrush->SetResourceObject(BackgroundTexture);
//	BackgroundImageBrush->SetImageSize(FVector2D(3840.f, 2160.f));
	BackgroundImageBrush->SetImageSize(FVector2D(BackgroundTexture->GetSizeX(), BackgroundTexture->GetSizeY()));

	ChildSlot
		[
			SNew(SOverlay)
				+ SOverlay::Slot()
				//.HAlign(HAlign_Fill)
				//.VAlign(VAlign_Fill)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SImage)
						.Image(BackgroundImageBrush)
				]
		];
}
