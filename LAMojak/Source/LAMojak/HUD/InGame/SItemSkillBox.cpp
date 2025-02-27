// Fill out your copyright notice in the Description page of Project Settings.

#include "../UResourceManager.h"
#include "SItemSkillBox.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SItemSkillBox::Construct(const FArguments& InArgs)
{
	UResourceManager* ResourceManager = UResourceManager::Get();
	UTexture2D* BoxTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(BoxName));
	UTexture2D* KeyBoxTexture = LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(KeyBoxName));

	FSlateBrush* BoxImageBrush = new FSlateBrush();
	BoxImageBrush->SetResourceObject(BoxTexture);
	BoxImageBrush->SetImageSize(FVector2D(BoxTexture->GetSizeX(), BoxTexture->GetSizeY()));

	FSlateBrush* KeyBoxImageBrush = new FSlateBrush();
	KeyBoxImageBrush->SetResourceObject(KeyBoxTexture);
	KeyBoxImageBrush->SetImageSize(FVector2D(KeyBoxTexture->GetSizeX(), KeyBoxTexture->GetSizeY()));

	DefaultImageBrush = new FSlateBrush();
	DefaultImageBrush->SetResourceObject(LoadObject<UTexture2D>(nullptr, *ResourceManager->GetTexturePath(DefaulImageName)));
	DefaultImageBrush->SetImageSize(FVector2D(50, 50));

	// get font
	FSlateFontInfo Font = FSlateFontInfo(LoadObject<UObject>(nullptr, *ResourceManager->GetFontAssetPath("Danjo-bold-Regular_Font.Danjo-bold-Regular_Font")), 15);

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(BoxImageBrush)
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(ImageBox, SImage)
				.Image(DefaultImageBrush)
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			[
				SNew(SImage)
				.Image(KeyBoxImageBrush)
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			[
				SAssignNew(KeyText, STextBlock)
				.Text(FText::FromString("Q"))
				.Font(Font)
			]
		];
}
void SItemSkillBox::SetImageBox(UTexture2D* BoxTexture)
{
	if (BoxTexture == nullptr)
	{
		return;
	}

	FSlateBrush* BoxImageBrush = new FSlateBrush();
	BoxImageBrush->SetResourceObject(BoxTexture);
	BoxImageBrush->SetImageSize(FVector2D(BoxTexture->GetSizeX(), BoxTexture->GetSizeY()));

	ImageBox->SetImage(BoxImageBrush);
}
void SItemSkillBox::SetKey(FString Key)
{
	KeyText->SetText(FText::FromString(Key));
}
void SItemSkillBox::SetImageBlank()
{
	ImageBox->SetImage(DefaultImageBrush);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
