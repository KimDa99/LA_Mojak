// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"
/**
 * 
 */
class LAMOJAK_API SBottomRightBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBottomRightBar){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	const FString ShopTextureName = "InGame-shopping";
	const FString ExpeditionTextureName = "InGame-group-fill";
	const FString CharacterTextureName = "InGame-Chat";
	const FString AdventureTextureName = "InGame-Adventure";
	const FString PathFinderTextureName = "InGame-Compass";
	const FString CommunityTextureName = "InGame-Community";
	const FString SettingTextureName = "InGame-Setting";

	const FString ShopTextKey = "InGame-BottomRight-Shop";
	const FString ExpeditionTextKey = "InGame-BottomRight-Expedition";
	const FString CharacterTextKey = "InGame-BottomRight-Character";
	const FString AdventureTextKey = "InGame-BottomRight-Adventure";
	const FString PathFinderTextKey = "InGame-BottomRight-PathFind";
	const FString CommunityTextKey = "InGame-BottomRight-Community";
	const FString SettingTextKey = "InGame-BottomRight-Setting";

	const FString ButtonStyleName = "BasicButtonBrush";
	const FString TitleFontName = "Danjo-bold-Regular_Font";
};
