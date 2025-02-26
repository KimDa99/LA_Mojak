// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

class LAMOJAK_API SMainBoard : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainBoard) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void AddWidget( TSharedRef<SWidget> Widget, const FMargin& Padding, EHorizontalAlignment HAlign, EVerticalAlignment VAlign);
	void RemoveWidget(TSharedRef<SWidget> Widget);

private:
	TSharedPtr<SOverlay> ContentLay;
	
//public:
//	void SetTitleText(FText TitleText);
//
//	void SetContentsText(FText ContentsText);
//
//	virtual bool SupportsKeyboardFocus() const override { return true; }
//
//private:
//	TSharedPtr<STextBlock> TitleTextWidget;
//
//	TSharedPtr<STextBlock> ContentsTextWidget;
};
