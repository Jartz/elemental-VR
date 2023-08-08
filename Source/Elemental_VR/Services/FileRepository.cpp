#include "FileRepository.h"



void UFileRepository::DownloadFile(const FString& FileURL, const FString& NameFile)
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetURL(FileURL);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UFileRepository::OnFileDownloaded, NameFile);
	HttpRequest->ProcessRequest();
}

void UFileRepository::OnFileDownloaded(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FString NameFile)
{
	if (bWasSuccessful && Response->GetResponseCode() == EHttpResponseCodes::Ok)
	{
		TArray<uint8> ResponseData = Response->GetContent();
		FString FileName = NameFile;
		UE_LOG(LogTemp, Warning, TEXT("Imagen download"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error en la descarga del archivo."));
	}
}