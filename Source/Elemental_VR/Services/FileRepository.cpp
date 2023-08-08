#include "FileRepository.h"
#include "Misc/FileHelper.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "IPlatformFilePak.h"



void UFileRepository::DownloadFile(const FString& FileURL, const FString& NameFile)
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetURL(FileURL);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UFileRepository::OnFileDownloaded, NameFile);
	HttpRequest->ProcessRequest();
}

void UFileRepository::OnFileDownloaded(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FString FileName)
{
	if (bWasSuccessful && Response->GetResponseCode() == EHttpResponseCodes::Ok)
	{
		TArray<uint8> BinaryData = Response->GetContent();
		FString SavePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + FileName;

		if (FFileHelper::SaveArrayToFile(BinaryData, *SavePath))
		{
			UE_LOG(LogTemp, Warning, TEXT("Archivo guardado en: %s"), *SavePath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error al guardar el archivo en: %s"), *SavePath);
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error en la descarga del archivo."));
	}
}

