// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JoystickPluginDevGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class JOYSTICKPLUGINDEV_API AJoystickPluginDevGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	
};
