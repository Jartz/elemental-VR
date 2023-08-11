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


bool USendPositionToServer::SendLocation(FString PositionArrayString, FString LocationHead)
{
	
	ULocationApiManager* LocationService = NewObject<ULocationApiManager>();
	LocationService->Send(PositionArrayString,LocationHead);
	return true;
}
