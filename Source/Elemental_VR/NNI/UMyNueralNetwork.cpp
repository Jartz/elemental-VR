#include "UMyNueralNetwork.h"


#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "Http.h"
using namespace std;


UMyNueralNetwork::UMyNueralNetwork()
{
	Network = nullptr;
}
TArray<float> UMyNueralNetwork::URunModel()
{
	// Create result array
	
	TArray<float> OutputTensor;

	// Create Network object if null
	if (Network == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Cargando network"));
		UObject* TransientPackage = (UObject*)GetTransientPackage();
		Network = NewObject<UNeuralNetwork>(TransientPackage, UNeuralNetwork::StaticClass());
		FString FileName = TEXT("PoseUp.onnx");
		FString SavePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + FileName;
		const FString& ONNXModelFilePath = SavePath;
		 Network->SetDeviceType(ENeuralDeviceType::CPU);
		 if (Network->Load(ONNXModelFilePath))
		{
			UE_LOG(LogTemp, Warning, TEXT("Neural Network loaded successfully."))
		 	TArray<float> MyFloatArray;
		 	MyFloatArray.Add(1.0);

		 	TArray<TArray<float>> InputData = {
		 		 {-152.67,3.19,43.97},
				 {-147.53,13.03,43.9},
				 {-142.68,19.38,43.9},
				 {-140.52,19.9,43.9},
				 {-143.39,8.9,43.8},
				 {-146.85,-1.47,43.4}
		 	};
		 	
		 	// Aplana la entrada
		 	TArray<float> FlattenedInput = FlattenInput(InputData);
		 	Network->SetInputFromArrayCopy(FlattenedInput);
		 	Network->Run();
		 	UE_LOG(LogTemp, Log, TEXT("Neural Network Inference complete."))
		 	// Read and print OutputTensor
		 	OutputTensor = Network->GetOutputTensor().GetArrayCopy<float>();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("UNeuralNetwork could not loaded from %s"), *ONNXModelFilePath);
			return OutputTensor;
		}
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("network no es null"));
	}

	UE_LOG(LogTemp, Warning, TEXT("Results created successfully."))
	return OutputTensor;
}


TArray<float> UMyNueralNetwork::FlattenInput(const TArray<TArray<float>>& InputData)
{
	TArray<float> FlattenedData;

	for (const TArray<float>& SubArray : InputData)
	{
		FlattenedData.Append(SubArray);
	}

	return FlattenedData;
}

