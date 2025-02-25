// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

/**
 * 
 */
class LAMOJAK_API SImageTextButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SImageTextButton)
		: _ButtonStyle(nullptr)
		, _OnClicked()
		, _ImageBrush(nullptr)
		, _FontInfo(FSlateFontInfo())
		, _ButtonText(FText::GetEmpty())
		, _Padding(FMargin(5.0f))
		, _Color(FColor::Black)
		{
		}

		SLATE_ARGUMENT(USlateWidgetStyleAsset*, ButtonStyle)
		SLATE_EVENT(FOnClicked, OnClicked)
		SLATE_ARGUMENT(const FSlateBrush*, ImageBrush)
		SLATE_ARGUMENT(FSlateFontInfo, FontInfo)
		SLATE_ARGUMENT(FText, ButtonText)
		SLATE_ARGUMENT(FMargin, Padding)
		SLATE_ARGUMENT(FSlateColor, Color)		

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

	void SetText(const FText& Text);

	void SetImage(UTexture2D* Texture);

private:
	TSharedPtr<SButton> ButtonWidget;
	TSharedPtr<STextBlock> TextWidget;
	TSharedPtr<SImage> ImageWidget;
};
