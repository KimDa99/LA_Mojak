// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SSliderBar.h"


class LAMOJAK_API SStatusBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SStatusBar)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void GenerateSkillItemBoxs();

	void SetSkillItemShortcuts();

	void UpdateImageKeyBox(const int index, const bool IsSkill);
	void UpdateImageKeyItemox(const int index);

private:
	int32 MaxHealth = 915;
	int32 CurrentHealth = 900;
	int32 MaxMana = 793;
	int32 CurrentMana = 777;

	TSharedPtr<SSliderBar> HealthBar;
	TSharedPtr<SSliderBar> ManaBar;

	TSharedPtr<SHorizontalBox> SkillBar0;
	TSharedPtr<SHorizontalBox> SkillBar1;

	TSharedPtr<SHorizontalBox> ItemBar0;
	TSharedPtr<SHorizontalBox> ItemBar1;

	const TArray<FString> SkillNames = { "InGame-CrossBlade", "InGame-PunshingDraw", "InGame-FuriousClaw", "InGame-FatalSword", "InGame-WildRush", "InGame-GroundSmash" };
	const TArray<FString> SkillShortCutKeys = { "Q", "W", "E", "R", "A", "S", "D", "F"};

	const TArray<FString> ItemNames = { "InGame-HealingPotion"};
	const TArray<FString> ItemShortCutKeys = { "F1", "5", "6", "7", "8", "9", "1", "2", "3", "4"};

};
