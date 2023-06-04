// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FGetJoystickUnrealModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	DECLARE_DELEGATE_TwoParams(FGetCatalogCompleteDelegate, bool, FString);
	static FGetCatalogCompleteDelegate GetCatalogCompleteDelegate;

	DECLARE_DELEGATE_TwoParams(FGetConfigContentCompleteDelegate, bool, FString);
	static FGetConfigContentCompleteDelegate GetConfigContentCompleteDelegate;

	static void FetchConfigContent(const TArray<FString> ContentIDs);
	static void FetchCatalogContent();
	static void SetRuntimeEnvironmentAPIKey(FString apiKey);
	static void OnFetchConfigContentComplete(bool Succeed, FString ResponseJsonData);
	static void OnFetchCatalogContentComplete(bool Succeed, FString ResponseJsonData);
};