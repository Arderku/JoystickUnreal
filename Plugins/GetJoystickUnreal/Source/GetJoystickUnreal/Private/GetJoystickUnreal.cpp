// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnreal.h"
#include "GetJoystickUnrealServices.h"
#include "GetJoystickUnrealSettings.h"

#define LOCTEXT_NAMESPACE "FGetJoystickUnrealModule"

void FGetJoystickUnrealModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: GetJoystickUnreal Startup Module!"));

	GetJoystickUnrealServices::GetConfigContentCompleteDelegate.BindStatic(&OnFetchConfigContentComplete);
	GetJoystickUnrealServices::GetCatalogCompleteDelegate.BindStatic(&OnFetchCatalogContentComplete);
}

void FGetJoystickUnrealModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FGetJoystickUnrealModule::FetchConfigContent(const TArray<FString> ContentIDs)
{
	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: FetchConfigContent"));
	GetJoystickUnrealServices::PerformHttpPost(ContentIDs);
}

void FGetJoystickUnrealModule::FetchCatalogContent()
{
	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: FetchCatalogContent"));
	GetJoystickUnrealServices::PerformHttpGetCatalog();
}

void FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(FString apiKey)
{
	UGetJoystickUnrealSettings::SetCurrentEnvironmentAPIKey(apiKey);

	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: SetRuntimeEnvironmentAPIKey: %s"), *apiKey);
}

void FGetJoystickUnrealModule::OnFetchConfigContentComplete(bool Succeed, FString ResponseJsonData)
{
	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: OnFetchConfigContentComplete: %s"), *ResponseJsonData);
}

void FGetJoystickUnrealModule::OnFetchCatalogContentComplete(bool Succeed, FString ResponseJsonData)
{
	UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: OnFetchCatalogContentComplete: %s"), *ResponseJsonData);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGetJoystickUnrealModule, GetJoystickUnreal)