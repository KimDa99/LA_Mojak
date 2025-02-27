// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class LAMOJAK_API SItemSkillBox : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SItemSkillBox){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void SetImageBox(UTexture2D* BoxTexture);
	void SetKey(FString Key);
	void SetImageBlank();

private:
	FSlateBrush* DefaultImageBrush;

	const FString BoxName = "InGame-BlankBox";
	const FString KeyBoxName = "InGame-KeyBox";
	const FString DefaulImageName = "transparent_picture";
	TSharedPtr<SImage> ImageBox;
	TSharedPtr<STextBlock> KeyText;
	
};
