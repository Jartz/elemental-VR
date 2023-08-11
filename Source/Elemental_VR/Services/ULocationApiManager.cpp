
#include "ULocationApiManager.h"
#include "Http.h"



bool ULocationApiManager::Send(FString value,FString LocationHead)
{
		const FString Url = TEXT("https://dev.biotrade.app/api/location");
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		JsonObject->SetStringField(TEXT("location"), value);
		JsonObject->SetStringField(TEXT("location_head"), LocationHead);
		JsonObject->SetStringField(TEXT("type"), TEXT("Circle"));
	
		FString JsonString = "";
		TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
	
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
		HttpRequest->SetVerb(TEXT("POST"));
	
		HttpRequest->SetURL(Url);
		HttpRequest->SetContentAsString(JsonString);
	
		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	
		//HttpRequest->OnProcessRequestComplete().BindUObject(this, &USendHandLocation::OnResponseReceived);
	
		HttpRequest->ProcessRequest();
		return true;
	
}