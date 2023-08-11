#pragma once
#include "Http.h"
#include "FileRepository.generated.h"

UCLASS()
class UFileRepository : public UObject
{
	GENERATED_BODY()
public:
	void DownloadFile(const FString& FileURL, const FString& SavePath);
	void OnFileDownloaded(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FString SavePath);
	bool CheckFileExistence(const FString& FileName);
	void ValidateModelOnnx();
};
