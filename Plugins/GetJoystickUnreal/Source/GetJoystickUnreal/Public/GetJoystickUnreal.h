// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FGetJoystickUnrealModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static void FetchConfigContent(const TArray<FString> ContentIDs);
	static void FetchCatalogContent();
	static void SetRuntimeEnvironmentAPIKey(FString apiKey);
};
