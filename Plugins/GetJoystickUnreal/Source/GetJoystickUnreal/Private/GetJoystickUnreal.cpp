// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnreal.h"
#include "GetJoystickUnrealServices.h"
#include "GetJoystickUnrealSettings.h"

#define LOCTEXT_NAMESPACE "FGetJoystickUnrealModule"

FGetJoystickUnrealModule::FGetCatalogCompleteDelegate FGetJoystickUnrealModule::GetCatalogCompleteDelegate;
FGetJoystickUnrealModule::FGetConfigContentCompleteDelegate FGetJoystickUnrealModule::GetConfigContentCompleteDelegate;

void FGetJoystickUnrealModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FGetJoystickUnrealModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FGetJoystickUnrealModule::FetchConfigContent(const TArray<FString> ContentIDs)
{
	GetJoystickUnrealServices::GetConfigContentCompleteDelegate.BindStatic(&OnFetchConfigContentComplete);
	GetJoystickUnrealServices::PerformHttpPost(ContentIDs);
}

void FGetJoystickUnrealModule::FetchCatalogContent()
{
	GetJoystickUnrealServices::GetCatalogCompleteDelegate.BindStatic(&OnFetchCatalogContentComplete);
	GetJoystickUnrealServices::PerformHttpGetCatalog();
}

void FGetJoystickUnrealModule::SetRuntimeEnvironmentAPIKey(FString apiKey)
{
	UGetJoystickUnrealSettings::SetCurrentEnvironmentAPIKey(apiKey);
}

void FGetJoystickUnrealModule::OnFetchConfigContentComplete(bool Succeed, FString ResponseJsonData)
{
	GetJoystickUnrealServices::GetConfigContentCompleteDelegate.Unbind();
	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.ExecuteIfBound(Succeed, ResponseJsonData);
}

void FGetJoystickUnrealModule::OnFetchCatalogContentComplete(bool Succeed, FString ResponseJsonData)
{
	GetJoystickUnrealServices::GetCatalogCompleteDelegate.Unbind();
	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.ExecuteIfBound(Succeed, ResponseJsonData);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGetJoystickUnrealModule, GetJoystickUnreal)