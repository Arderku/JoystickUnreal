// Fill out your copyright notice in the Description page of Project Settings.


#include "GetJoystickUnrealSettings.h"

FString UGetJoystickUnrealSettings::CurrentEnvironmentAPIKey = "";

void UGetJoystickUnrealSettings::SetCurrentEnvironmentAPIKey(const FString& ApiKey)
{
	CurrentEnvironmentAPIKey = ApiKey;
}

FString UGetJoystickUnrealSettings::GetCurrentEnvironmentAPIKey()
{
	return CurrentEnvironmentAPIKey;
}
