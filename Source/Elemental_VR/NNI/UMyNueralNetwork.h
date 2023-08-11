#pragma once
#include "CoreMinimal.h"
#include "NeuralNetwork.h"
#include "UObject/Object.h"
#include "Http.h"
#include "UMyNueralNetwork.generated.h"

UCLASS()
class UMyNueralNetwork  : public UNeuralNetwork
{

	GENERATED_BODY()
	
public:
    
	UPROPERTY(Transient)
	UNeuralNetwork* Network = nullptr;
	UMyNueralNetwork();
	TArray<float> URunModel();
	TArray<float> FlattenInput(const TArray<TArray<float>>& InputData);
	
};
