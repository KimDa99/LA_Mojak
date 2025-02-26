// Fill out your copyright notice in the Description page of Project Settings.

#include "TextManager.h"

UTextManager* UTextManager::TextManager = nullptr;

#define LOCTEXT_NAMESPACE "LAMojak"

FText UTextManager::GetLocalizedText(const FString& Key) const
{
	if (LocalizationMap.Contains(Key))
	{
		return LocalizationMap[Key];
	}
	return FText::FromString("Missing Text");

}

void UTextManager::InitializeLocalization()
{
	LocalizationMap.Add("ServerSelectionTitle", LOCTEXT("ServerSelectionTitle", "서버 선택"));
	LocalizationMap.Add("ServerColumn", LOCTEXT("ServerColumn", "서버"));
	LocalizationMap.Add("StatusColumn", LOCTEXT("StatusColumn", "상태"));
	LocalizationMap.Add("CharacterColumn", LOCTEXT("StatusColumn", "캐릭터"));
	LocalizationMap.Add("EnterButton", LOCTEXT("StatusColumn", "입장"));
}

#define LOCTEXT_NAMESPACE "LAMojak"