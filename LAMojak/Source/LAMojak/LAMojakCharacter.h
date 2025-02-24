// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LAMojakCharacter.generated.h"

UCLASS(Blueprintable)
class ALAMojakCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALAMojakCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

};

