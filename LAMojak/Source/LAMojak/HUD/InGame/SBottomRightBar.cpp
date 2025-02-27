// Fill out your copyright notice in the Description page of Project Settings.

#include "SBottomRightBar.h"
#include "../UResourceManager.h"
#include "../TextManager.h"
#include "SBottomRightButton.h"

void SBottomRightBar::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* ShopTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(ShopTextureName));

	FSlateBrush* ShopImageBrush = new FSlateBrush();
	ShopImageBrush->SetResourceObject(ShopTexture);
	ShopImageBrush->SetImageSize(FVector2D(ShopTexture->GetSizeX()*2.f, ShopTexture->GetSizeY() * 2.f));

	UTexture2D* ExpeditionTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(ExpeditionTextureName));
	FSlateBrush* ExpeditionImageBrush = new FSlateBrush();
	ExpeditionImageBrush->SetResourceObject(ExpeditionTexture);
	ExpeditionImageBrush->SetImageSize(FVector2D(ExpeditionTexture->GetSizeX() * 2.f, ExpeditionTexture->GetSizeY() * 2.f));

	UTexture2D* CharacterTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(CharacterTextureName));
	FSlateBrush* CharacterImageBrush = new FSlateBrush();
	CharacterImageBrush->SetResourceObject(CharacterTexture);
	CharacterImageBrush->SetImageSize(FVector2D(CharacterTexture->GetSizeX() * 2.f, CharacterTexture->GetSizeY() * 2.f));

	UTexture2D* AdventureTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(AdventureTextureName));
	FSlateBrush* AdventureImageBrush = new FSlateBrush();
	AdventureImageBrush->SetResourceObject(AdventureTexture);
	AdventureImageBrush->SetImageSize(FVector2D(AdventureTexture->GetSizeX() * 2.f, AdventureTexture->GetSizeY() * 2.f));

	UTexture2D* PathFinderTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(PathFinderTextureName));
	FSlateBrush* PathFinderImageBrush = new FSlateBrush();
	PathFinderImageBrush->SetResourceObject(PathFinderTexture);
	PathFinderImageBrush->SetImageSize(FVector2D(PathFinderTexture->GetSizeX() * 2.f, PathFinderTexture->GetSizeY() * 2.f));

	UTexture2D* CommunityTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(CommunityTextureName));
	FSlateBrush* CommunityImageBrush = new FSlateBrush();
	CommunityImageBrush->SetResourceObject(CommunityTexture);
	CommunityImageBrush->SetImageSize(FVector2D(CommunityTexture->GetSizeX() * 2.f, CommunityTexture->GetSizeY() * 2.f));

	UTexture2D* SettingTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(SettingTextureName));
	FSlateBrush* SettingImageBrush = new FSlateBrush();
	SettingImageBrush->SetResourceObject(SettingTexture);
	SettingImageBrush->SetImageSize(FVector2D(SettingTexture->GetSizeX() * 2.f, SettingTexture->GetSizeY() * 2.f));
	

	FSlateFontInfo TextStyle(LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath(TitleFontName)), 15);

	const FText ShopText = UTextManager::Get()->GetLocalizedText(ShopTextKey);
	const FText ExpeditionText = UTextManager::Get()->GetLocalizedText(ExpeditionTextKey);
	const FText CharacterText = UTextManager::Get()->GetLocalizedText(CharacterTextKey);
	const FText AdventureText = UTextManager::Get()->GetLocalizedText(AdventureTextKey);
	const FText PathFinderText = UTextManager::Get()->GetLocalizedText(PathFinderTextKey);
	const FText CommunityText = UTextManager::Get()->GetLocalizedText(CommunityTextKey);
	const FText SettingText = UTextManager::Get()->GetLocalizedText(SettingTextKey);

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, *ResourceManager->GetBrushAssetPath("BasicButtonBrush"));

	ChildSlot
	[
		SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(ShopImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(ShopText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(ExpeditionImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(ExpeditionText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(CharacterImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(CharacterText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(AdventureImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(AdventureText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(PathFinderImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(PathFinderText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(CommunityImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(CommunityText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10.f)
			[
				SNew(SBottomRightButton)
					.ButtonStyle(ButtonStyle)
					.OnClicked(FOnClicked())
					.ImageBrush(SettingImageBrush)
					.FontInfo(TextStyle)
					.ButtonText(SettingText)
					.Padding(FMargin(5.0f))
					.Color(FSlateColor(FColor::White))
			]
	];
}
