// Fill out your copyright notice in the Description page of Project Settings.


#include "GetJoystickUnrealServices.h"
#include "GetJoystickUnrealSettings.h"
#include "Misc/SecureHash.h"

GetJoystickUnrealServices::FHttpRequestCompleteDelegate GetJoystickUnrealServices::HttpRequestCompleteDelegate;

GetJoystickUnrealServices::GetJoystickUnrealServices()
{
}

GetJoystickUnrealServices::~GetJoystickUnrealServices()
{
}

void GetJoystickUnrealServices::PerformHttpPost(const TArray<FString>& ContentIds)
{
    FString Url = GetJoystickUnrealServices::GetConfigContentAPIUrl(ContentIds);
    FString currentAPIKey = UGetJoystickUnrealSettings::GetCurrentEnvironmentAPIKey();

    UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: HTTP POST URL: %s"), *Url);

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb("POST");
    HttpRequest->SetURL(Url);
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->AppendToHeader("x-api-key", currentAPIKey);

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    FString RequestBody;
    TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
    JsonWriter->Close();

    HttpRequest->SetContentAsString(RequestBody);

    HttpRequest->OnProcessRequestComplete().BindStatic([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
        if (bWasSuccessful && Response.IsValid())
        {
            // Request succeeded, handle the response here

            FString ResponseContent = Response->GetContentAsString();

            GetJoystickUnrealServices::HttpRequestCompleteDelegate.ExecuteIfBound(true, ResponseContent);

            UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: HTTP POST response: %s"), *ResponseContent);
        }
        else
        {
            GetJoystickUnrealServices::HttpRequestCompleteDelegate.ExecuteIfBound(false, "Request Failed");

            // Request failed
            UE_LOG(LogTemp, Error, TEXT("JoystickUnreal: HTTP POST request failed!"));
        }
        });

    HttpRequest->ProcessRequest();
}

void GetJoystickUnrealServices::PerformHttpGetCatalog()
{
    FString Url = GetJoystickUnrealServices::GetCatalogConfigAPIUrl();
    FString currentAPIKey = UGetJoystickUnrealSettings::GetCurrentEnvironmentAPIKey();

    UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: HTTP GET URL: %s"), *Url);

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb("GET");
    HttpRequest->SetURL(Url);
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->AppendToHeader("x-api-key", currentAPIKey);

    HttpRequest->OnProcessRequestComplete().BindStatic([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
        if (bWasSuccessful && Response.IsValid())
        {
            int32 ResponseCode = Response->GetResponseCode();
            FString ResponseContent = Response->GetContentAsString();

            GetJoystickUnrealServices::HttpRequestCompleteDelegate.ExecuteIfBound(true, ResponseContent);
            // Process the response content
            // ...
            UE_LOG(LogTemp, Warning, TEXT("JoystickUnreal: HTTP GET response: %s"), *ResponseContent);
        }
        else
        {
            GetJoystickUnrealServices::HttpRequestCompleteDelegate.ExecuteIfBound(false, "Request Failed");
            // Handle request failure
            UE_LOG(LogTemp, Error, TEXT("JoystickUnreal: HTTP GET request failed!"));
        }
        });

    if (!HttpRequest->ProcessRequest())
    {
        UE_LOG(LogTemp, Error, TEXT("JoystickUnreal: HTTP GET request failed!"));
    }
}

FString GetJoystickUnrealServices::GetConfigContentAPIUrl(const TArray<FString>& ContentIds)
{
    FString CombinedIds;
    for (int32 i = 0; i < ContentIds.Num(); i++)
    {
        CombinedIds += FString::Printf(TEXT("\"%s\""), *ContentIds[i]);

        if (i < ContentIds.Num() - 1)
        {
            CombinedIds += TEXT(",");
        }
    }

    bool bShouldSerialize = true;

    FString ResponseTypeParam = "&responseType=serialized";
    FString AppendParam = bShouldSerialize ? ResponseTypeParam : FString();

    FString APIUrl = FString::Printf(TEXT("https://api.getjoystick.com/api/v1/combine/?c=[%s]&dynamic=true%s"), *CombinedIds, *AppendParam);

    return APIUrl;
}

FString GetJoystickUnrealServices::GetCatalogConfigAPIUrl()
{
    FString Url = "https://api.getjoystick.com/api/v1/env/catalog";
    
    return Url;
}
