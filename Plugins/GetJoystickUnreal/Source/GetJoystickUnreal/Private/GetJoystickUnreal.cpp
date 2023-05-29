// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnreal.h"
#include "GetJoystickUnrealServices.h"

#define LOCTEXT_NAMESPACE "FGetJoystickUnrealModule"

void FGetJoystickUnrealModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("TEST GetJoystickUnreal Startup Module!"));
}

void FGetJoystickUnrealModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

void FGetJoystickUnrealModule::FetchConfigContent(const TArray<FString> ContentIDs)
{
	UE_LOG(LogTemp, Warning, TEXT("TEST FetchConfigContent"));
	GetJoystickUnrealServices::PerformHttpPost(ContentIDs);
}

void FGetJoystickUnrealModule::FetchCatalogContent()
{
	UE_LOG(LogTemp, Warning, TEXT("TEST FetchCatalogContent"));
}

void FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(FString apiKey)
{
	UE_LOG(LogTemp, Warning, TEXT("TEST SetRuntimeEnvironmentAPIKey"));
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGetJoystickUnrealModule, GetJoystickUnreal)