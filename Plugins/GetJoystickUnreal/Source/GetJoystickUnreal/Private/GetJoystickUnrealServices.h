// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Http.h"
#include "JsonUtilities.h"

/**
 * 
 */
class GetJoystickUnrealServices
{
public:
	GetJoystickUnrealServices();
	~GetJoystickUnrealServices();

	DECLARE_DELEGATE_TwoParams(FGetCatalogCompleteDelegate, bool, FString);
	static FGetCatalogCompleteDelegate GetCatalogCompleteDelegate;

	DECLARE_DELEGATE_TwoParams(FGetConfigContentCompleteDelegate, bool, FString);
	static FGetConfigContentCompleteDelegate GetConfigContentCompleteDelegate;

	static void PerformHttpPost(const TArray<FString>& ContentIds);
	static void PerformHttpGetCatalog();

	static FString GetConfigContentAPIUrl(const TArray<FString>& ContentIds);
	static FString GetCatalogConfigAPIUrl();
};
