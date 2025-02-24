// Copyright Epic Games, Inc. All Rights Reserved.

#include "LAMojakGameMode.h"
#include "LAMojakPlayerController.h"
#include "LAMojakCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "HUD/LAMojakHUD.h"

ALAMojakGameMode::ALAMojakGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ALAMojakPlayerController::StaticClass();
	HUDClass = ALAMojakHUD::StaticClass();
}