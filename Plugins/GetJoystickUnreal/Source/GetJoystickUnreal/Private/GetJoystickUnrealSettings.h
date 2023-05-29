// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GetJoystickUnrealSettings.generated.h"

/**
 * 
 */
UCLASS()
class GETJOYSTICKUNREAL_API UGetJoystickUnrealSettings : public UObject
{
	GENERATED_BODY() 

public:
   UFUNCTION(BlueprintCallable, Category = "GetJoystickUnreal")
   static void SetCurrentEnvironmentAPIKey(const FString& ApiKey);

    UFUNCTION(BlueprintPure, Category = "GetJoystickUnreal")
    static FString GetCurrentEnvironmentAPIKey();

private:
    static FString CurrentEnvironmentAPIKey;
};
