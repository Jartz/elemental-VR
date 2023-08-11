// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Http.h"
#include "SendPositionToServer.generated.h"

/**
 * 
 */
UCLASS()
class ELEMENTAL_VR_API USendPositionToServer : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable,Category="RestAPI")
	static bool SendLocation(FString PositionArrayString,FString LocationHead);
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
};
