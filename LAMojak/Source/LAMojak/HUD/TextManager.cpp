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
	return FText::FromString("Missing");

}

void UTextManager::InitializeLocalization()
{
	LocalizationMap.Add("ServerSelectionTitle", LOCTEXT("ServerSelectionTitle", "서버 선택"));
	LocalizationMap.Add("ServerColumn", LOCTEXT("ServerColumn", "서버"));
	LocalizationMap.Add("StatusColumn", LOCTEXT("StatusColumn", "상태"));
	LocalizationMap.Add("CharacterColumn", LOCTEXT("StatusColumn", "캐릭터"));
	LocalizationMap.Add("EnterButton", LOCTEXT("StatusColumn", "입장"));

	LocalizationMap.Add("InGame-BottomRight-Shop", LOCTEXT("Shop", "로아샵"));
	LocalizationMap.Add("InGame-BottomRight-Expedition", LOCTEXT("Expedition", "원정대"));
	LocalizationMap.Add("InGame-BottomRight-Character", LOCTEXT("Character", "캐릭터"));
	LocalizationMap.Add("InGame-BottomRight-Adventure", LOCTEXT("Adventure", "모험"));
	LocalizationMap.Add("InGame-BottomRight-PathFind", LOCTEXT("PathFind", "길잡이"));
	LocalizationMap.Add("InGame-BottomRight-Community", LOCTEXT("Community", "커뮤니티"));
	LocalizationMap.Add("InGame-BottomRight-Setting", LOCTEXT("Setting", "설정"));
}

#define LOCTEXT_NAMESPACE "LAMojak"