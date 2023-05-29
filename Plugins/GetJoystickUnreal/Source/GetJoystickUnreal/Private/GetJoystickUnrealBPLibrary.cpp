// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnrealBPLibrary.h"
#include "GetJoystickUnreal.h"

UGetJoystickUnrealBPLibrary::UGetJoystickUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealRequestContent(TArray<FString> ContentIDs)
{
	FGetJoystickUnrealModule::FetchConfigContent(ContentIDs);
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealRequestCatalogContent()
{
	FGetJoystickUnrealModule::FetchCatalogContent();
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealSetRuntimeEnvironmentAPIKey(FString apiKey)
{
	FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(apiKey);
}