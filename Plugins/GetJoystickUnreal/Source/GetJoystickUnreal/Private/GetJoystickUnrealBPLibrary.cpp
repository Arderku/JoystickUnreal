// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnrealBPLibrary.h"
#include "GetJoystickUnreal.h"

UGetJoystickUnrealBPLibrary::UGetJoystickUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: Initialize"));
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealRequestContent(TArray<FString> ContentIDs)
{
	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.BindStatic(&GetJoystickUnrealFetchConfigContentCallback);
	FGetJoystickUnrealModule::FetchConfigContent(ContentIDs);
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealRequestCatalogContent()
{
	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.BindStatic(&GetJoystickUnrealFetchCatalogContentCallback);
	FGetJoystickUnrealModule::FetchCatalogContent();
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealSetRuntimeEnvironmentAPIKey(FString apiKey)
{
	FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(apiKey);
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealFetchConfigContentCallback(bool Succeed, FString ResponseJsonData)
{
	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.Unbind();
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchConfigContentCallback: %s"), *ResponseJsonData);
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealFetchCatalogContentCallback(bool Succeed, FString ResponseJsonData)
{
	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.Unbind();
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchCatalogContentCallback: %s"), *ResponseJsonData);
}