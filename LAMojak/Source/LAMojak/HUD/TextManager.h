// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TextManager.generated.h"

/**
 * 
 */
UCLASS()
class LAMOJAK_API UTextManager : public UObject
{
	GENERATED_BODY()

public:
	FText GetLocalizedText(const FString& Key) const;
	void InitializeLocalization();

	// get singleton instance
	static UTextManager* Get()
	{
		if (!TextManager)
		{
			TextManager = NewObject<UTextManager>();
			TextManager->AddToRoot();
		}
		return TextManager;
	}

private:
	static UTextManager* TextManager;
	TMap<FString, FText> LocalizationMap;
};
