// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UResourceManager.generated.h"

UCLASS()
class LAMOJAK_API UResourceManager : public UObject
{
	GENERATED_BODY()

public:
	FString GetTexturePath(const FString& TextureName) const;
	FString GetFontAssetPath(const FString& FontAssetName) const;
	FString GetBrushAssetPath(const FString& BrushAssetName) const;

	static UResourceManager* Get()
	{
		if (!ResourceManager)
		{
			ResourceManager = NewObject<UResourceManager>();
			ResourceManager->AddToRoot();
		}

		return ResourceManager;
	}
private:
	static UResourceManager* ResourceManager;

	// Paths for different types of resources
	const FString BaseTexturePath = "/Game/Resources/Images/";
	const FString BaseFontAssetPath = "/Game/Resources/Fonts/";
	const FString BaseBrushAssetPath = "/Game/Resources/Brushes/";
};
