// Fill out your copyright notice in the Description page of Project Settings.


#include "UResourceManager.h"

UResourceManager* UResourceManager::ResourceManager = nullptr;

FString UResourceManager::GetTexturePath(const FString& TextureName) const
{
	return BaseTexturePath + TextureName;
}

FString UResourceManager::GetFontAssetPath(const FString& UIAssetName) const
{
	return BaseFontAssetPath + UIAssetName;
}

FString UResourceManager::GetBrushAssetPath(const FString& BrushAssetName) const
{
	return BaseBrushAssetPath + BrushAssetName;
}
