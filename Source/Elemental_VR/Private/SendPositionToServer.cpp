// Fill out your copyright notice in the Description page of Project Settings.


#include "SendPositionToServer.h"
#include "CoreMinimal.h"
#include "Http.h"
#include "JsonUtilities.h"
#include "Json.h" 
#include "Elemental_VR/Services/ULocationApiManager.h"


void USendPositionToServer::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		FString responseBody = Response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Respuesta del servidor: %s"), *responseBody);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error en el request."));
	}
}


bool USendPositionToServer::SendLocation(FString value)
{
	
	ULocationApiManager* LocationService = NewObject<ULocationApiManager>();
	LocationService->Send(value);
	// const FString Url = TEXT("https://dev.biotrade.app/api/location");
	// TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	// JsonObject->SetStringField(TEXT("location"), value);
	//
	// FString JsonString = "";
	// TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
	// FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
	//
	// TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	// HttpRequest->SetVerb(TEXT("POST"));
	//
	// HttpRequest->SetURL(Url);
	// HttpRequest->SetContentAsString(JsonString);
	//
	// HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	//
	// //HttpRequest->OnProcessRequestComplete().BindUObject(this, &USendHandLocation::OnResponseReceived);
	//
	// HttpRequest->ProcessRequest();
	return true;
}
