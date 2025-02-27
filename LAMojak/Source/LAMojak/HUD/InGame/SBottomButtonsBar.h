// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

/**
 * 
 */
class LAMOJAK_API SBottomButtonsBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBottomButtonsBar){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

//private:
//
//	void CreateButton(FString TexturePath, FText ButtonText);//, FOnClicked ButtonClicked);
//
//	const FString ShopTextureName = "InGame-shopping";
//	const FString ExpeditionTextureName = "InGame-group-fill";
//	const FString CharacterTextureName = "InGame-Chat";
//	const FString AdventureTextureName = "InGame-Adventure";
//	const FString PathFinderTextureName = "InGame-Compass";
//	const FString CommunityTextureName = "InGame-Community";
//	const FString SettingTextureName = "InGame-Setting";
//
//	//FReply OnDefaultButtonClicked();
//
//	TSharedRef<SHorizontalBox> Container;

	//TSharedRef<SButton> ShopButton;
	//TSharedRef<SButton> ExpeditionButton;
	//TSharedRef<SButton> CharacterButton;
	//TSharedRef<SButton> AdventureButton;
	//TSharedRef<SButton> PathFinderButton;
	//TSharedRef<SButton> CommunityButton;
	//TSharedRef<SButton> SettingButton;

};
