#pragma once
#include "ULocationApiManager.generated.h"


UCLASS()
class ULocationApiManager : public UObject
{
	GENERATED_BODY()
public:
	bool Send(FString value,FString LocationHead);
};