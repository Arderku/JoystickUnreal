// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetJoystickUnrealBPLibrary.h"
#include "GetJoystickUnreal.h"

UGetJoystickUnrealBPLibrary* UGetJoystickUnrealBPLibrary::Instance = nullptr;

UGetJoystickUnrealBPLibrary::UGetJoystickUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

UGetJoystickUnrealBPLibrary* UGetJoystickUnrealBPLibrary::GetInstance()
{
	if (!Instance)
	{
		Instance = NewObject<UGetJoystickUnrealBPLibrary>(GetTransientPackage(), FName(TEXT("UGetJoystickUnrealBPLibrary")));
		check(Instance);
	}

	return Instance;
}

void UGetJoystickUnrealBPLibrary::BindFetchConfigContentComplete(FFetchConfigContentComplete FetchConfigContentCompleteDelegateParameter)
{
	FetchConfigContentCompleteDelegate = FetchConfigContentCompleteDelegateParameter;
}

void UGetJoystickUnrealBPLibrary::BindFetchCatalogContentComplete(FFetchCatalogContentComplete FetchCatalogContentCompleteDelegateParameter)
{
	FetchCatalogContentCompleteDelegate = FetchCatalogContentCompleteDelegateParameter;
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
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchConfigContentCallback: %s"), *ResponseJsonData);

	FGetJoystickUnrealModule::GetConfigContentCompleteDelegate.Unbind();

	UGetJoystickUnrealBPLibrary* SingletonInstance = UGetJoystickUnrealBPLibrary::GetInstance();
	if (SingletonInstance)
	{
		SingletonInstance->FetchConfigContentCompleteDelegate.ExecuteIfBound(Succeed, ResponseJsonData);
	}
}

void UGetJoystickUnrealBPLibrary::FetchCatalogContentComplete(bool Succeed, FString ResponseJsonData)
{
	UE_LOG(LogTemp, Warning, TEXT("UGetJoystickUnrealBPLibrary: GetJoystickUnrealFetchCatalogContentCallback: %s"), *ResponseJsonData);

	FGetJoystickUnrealModule::GetCatalogCompleteDelegate.Unbind();

	UGetJoystickUnrealBPLibrary* SingletonInstance = UGetJoystickUnrealBPLibrary::GetInstance();
	if (SingletonInstance)
	{
		SingletonInstance->FetchCatalogContentCompleteDelegate.ExecuteIfBound(Succeed, ResponseJsonData);
	}
}