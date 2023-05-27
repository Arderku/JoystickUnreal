// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * 
 */
class GetJoystickUnrealServices
{
public:
	GetJoystickUnrealServices();
	~GetJoystickUnrealServices();

	static void PerformHttpPost(const TArray<FString>& ContentIds);
	static FString GetConfigContentAPIUrl(const TArray<FString>& ContentIds);
};
