// Fill out your copyright notice in the Description page of Project Settings.


#include "Connection.h"
#include "Elemental_VR/Services/FileRepository.h"

// Sets default values
AConnection::AConnection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConnection::BeginPlay()
{
	Super::BeginPlay();

	UFileRepository* FileServices = NewObject<UFileRepository>();
	if (FileServices)
	{
		FileServices->DownloadFile(TEXT("https://biotrade.app/PoseUp.onnx"),TEXT("PoseUp.onnx"));
	}
	
}

// Called every frame
void AConnection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

