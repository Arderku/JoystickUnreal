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
	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.BindStatic(&FetchConfigContentComplete);
	FGetJoystickUnrealModule::FetchConfigContent(ContentIDs);
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealRequestCatalogContent()
{
	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.BindStatic(&FetchCatalogContentComplete);
	FGetJoystickUnrealModule::FetchCatalogContent();
}

void UGetJoystickUnrealBPLibrary::GetJoystickUnrealSetRuntimeEnvironmentAPIKey(FString apiKey)
{
	FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(apiKey);
}

void UGetJoystickUnrealBPLibrary::FetchConfigContentComplete(bool Succeed, FString ResponseJsonData)
{
	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.Unbind();
	UGetJoystickUnrealBPLibrary::GetJoystickUnrealFetchConfigContentCallback(Succeed, ResponseJsonData);
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchConfigContentCallback: %s"), *ResponseJsonData);
}

void UGetJoystickUnrealBPLibrary::FetchCatalogContentComplete(bool Succeed, FString ResponseJsonData)
{
	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.Unbind();
	UGetJoystickUnrealBPLibrary::GetJoystickUnrealFetchCatalogContentCallback(Succeed, ResponseJsonData);
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchCatalogContentCallback: %s"), *ResponseJsonData);
}