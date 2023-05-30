// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"


/**
 * 
 */
class GetJoystickUnrealServices
{
public:
	GetJoystickUnrealServices();
	~GetJoystickUnrealServices();

	static void PerformHttpPost(const TArray<FString>& ContentIds);
	static void PerformHttpGetCatalog();
	static void OnHttpGetResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	static FString GetConfigContentAPIUrl(const TArray<FString>& ContentIds);
	static FString GetCatalogConfigAPIUrl();
};
