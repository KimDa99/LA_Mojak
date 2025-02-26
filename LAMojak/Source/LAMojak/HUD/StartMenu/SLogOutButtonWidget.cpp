// Fill out your copyright notice in the Description page of Project Settings.


#include "SLogOutButtonWidget.h"

void SLogOutButtonWidget::Construct(const FArguments& InArgs)
{
	UTexture2D* IconImage = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Resources/Images/StartMenu/logout-box-line.logout-box-line"));
	FSlateBrush* IconBrush = new FSlateBrush();
	IconBrush->SetResourceObject(IconImage);
	IconBrush->SetImageSize(FVector2D(100.f, 100.f));

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/Resources/Brushes/BasicButtonBrush.BasicButtonBrush"));

	ChildSlot
		[
			SNew(SButton)
			.ButtonStyle(ButtonStyle)
				[
					SNew(SImage)
					.Image(IconBrush)
				]
		];
}
