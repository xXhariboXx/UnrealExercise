// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "ZadanieRekrutacyjneController.h"


AZadanieRekrutacyjneController::AZadanieRekrutacyjneController()
	:
	APlayerController()
{

}

void AZadanieRekrutacyjneController::BeginPlay()
{
	Super::BeginPlay();
	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	//EnableInput(PlayerController);
	//SetupInputComponent();
}

void AZadanieRekrutacyjneController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Red", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourRed);		//Set on 'R' keyboard button
	InputComponent->BindAction("Green", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourGreen);	//Set on 'G' keyboard button
	InputComponent->BindAction("Blue", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourBlue);		//Set on 'B' keyboard button
	InputComponent->BindAction("Rand", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColorRandom);		//Set on 'X' keyboard button
}

void AZadanieRekrutacyjneController::SetLightColourRed()
{
	float red = 1;
	float green = 0;
	float blue = 0;
	SetLightColour_MultiplayerHandler(FLinearColor(red, green, blue, 1));
}

void AZadanieRekrutacyjneController::SetLightColourGreen()
{
	float red = 0;
	float green = 1;
	float blue = 0;
	SetLightColour_MultiplayerHandler(FLinearColor(red, green, blue, 1));
}

void AZadanieRekrutacyjneController::SetLightColourBlue()
{
	float red = 0;
	float green = 0;
	float blue = 1;
	SetLightColour_MultiplayerHandler(FLinearColor(red, green, blue, 1));
}

void AZadanieRekrutacyjneController::SetLightColorRandom()
{
	float red = std::rand() % 1000 * 0.001f;
	float green = std::rand() % 1000 * 0.001f;
	float blue = std::rand() % 1000 * 0.001f;
	SetLightColour_MultiplayerHandler(FLinearColor(red, green, blue, 1));
}

bool AZadanieRekrutacyjneController::IsBulbServer(ALightBulb * bulb)
{
	return (bulb != NULL) && Role == ROLE_Authority;
}

bool AZadanieRekrutacyjneController::IsBulbClient(ALightBulb * bulb)
{
	return (bulb != NULL) && Role < ROLE_Authority;
}

void AZadanieRekrutacyjneController::SetLightColour_MultiplayerHandler(FLinearColor newColor)
{
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ALightBulb * bulb = Cast<ALightBulb>(*ActorItr);
		if (IsBulbServer(bulb))
		//if(Role == ROLE_Authority)
		{
			//we are server
			UE_LOG(LogTemp, Warning, TEXT("Server is calling to clients"));
			NetMulticastSetColor(bulb, newColor);
		}
		//else
		else if (IsBulbClient(bulb))
		{
			//we are client	
			UE_LOG(LogTemp, Warning, TEXT("Client calling for server"));
			ServerSetLightColor(bulb, newColor);
		}
	}
}

void AZadanieRekrutacyjneController::ServerSetLightColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color)
{
	UE_LOG(LogTemp, Warning, TEXT("Server changing colour"));
	UE_LOG(LogTemp, Warning, TEXT("Server calling for clients"));
	NetMulticastSetColor(lightBulbActor, color);

}

bool AZadanieRekrutacyjneController::ServerSetLightColor_Validate(ALightBulb *lightBulbActor, FLinearColor color)
{
	return true;
}

void AZadanieRekrutacyjneController::NetMulticastSetColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color)
{
	UE_LOG(LogTemp, Warning, TEXT("Server executing clients"));
	//LightSource->SetLightColor(color, true);
	lightBulbActor->SetLightColor(color);
}

bool AZadanieRekrutacyjneController::NetMulticastSetColor_Validate(ALightBulb *lightBulbActor, FLinearColor color)
{
	return true;
}

