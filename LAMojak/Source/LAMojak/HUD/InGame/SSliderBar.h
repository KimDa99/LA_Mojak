// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LAMOJAK_API SSliderBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSliderBar)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	void SetAndUpdateSliderValue(float NewValue);
private:
	//TSharedPtr<STextBlock> SliderValueText;
	TSharedPtr<SHorizontalBox> SliderBox;


	const FVector2D SliderBarSize = FVector2D(256.f, 64.f);
	const FString OuterTextureName = "InGame-HP-Outer.InGame-HP-Outer";
	const FString InnerTextureName = "InGame-HP-Inner.InGame-HP-Inner";
	const FString FontName = "Danjo-bold-Regular_Font.Danjo-bold-Regular_Font";

	float SliderValue = 1.0f;

};
