// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "ServerInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct LAMOJAK_API FServerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Info")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Info")
	FText Status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Info")
	int32 NumberOfCharacter;
	
};
