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
	SetLightColorRandom();
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetActorClass() != this->GetActorClass())
		{
			ActorItr->SetOwner(this);
		}
	}
}

void AZadanieRekrutacyjneController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Red", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourRed);		//Set on 'R' keyboard button
	InputComponent->BindAction("Green", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourGreen);	//Set on 'G' keyboard button
	InputComponent->BindAction("Blue", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColourBlue);		//Set on 'B' keyboard button
	InputComponent->BindAction("Rand", IE_Pressed, this, &AZadanieRekrutacyjneController::SetLightColorRandom);		//Set on 'X' keyboard button
	InputComponent->BindAction("TogglePulse", IE_Pressed, this, &AZadanieRekrutacyjneController::TogglePulsing);	//Set on 'P' keyboard button
	InputComponent->BindAction("ToggleLight", IE_Pressed, this, &AZadanieRekrutacyjneController::ToggleLight);		//Set on 'L' keyboard button
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

bool AZadanieRekrutacyjneController::IsBulbServer(ALightBulb * lightBulbActor)
{
	return (lightBulbActor != NULL) && Role == ROLE_Authority;
}

bool AZadanieRekrutacyjneController::IsBulbClient(ALightBulb * lightBulbActor)
{
	return (lightBulbActor != NULL) && Role < ROLE_Authority;
}

void AZadanieRekrutacyjneController::TogglePulsing()
{
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ALightBulb * lightBulbActor = Cast<ALightBulb>(*ActorItr);
		if (IsBulbServer(lightBulbActor))
		{
			//we are server
			lightBulbActor->NetMulticastTogglePulsing();
		}
		else if (IsBulbClient(lightBulbActor))
		{
			//we are client	
			ServerTogglePulsing(lightBulbActor);
		}
	}
}

void AZadanieRekrutacyjneController::ToggleLight()
{
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ALightBulb * lightBulbActor = Cast<ALightBulb>(*ActorItr);
		if (IsBulbServer(lightBulbActor))
		{
			//we are server
			lightBulbActor->NetMulticastToggleLight();
		}
		else if (IsBulbClient(lightBulbActor))
		{
			//we are client	
			ServerToggleLight(lightBulbActor);
		}
	}
}

void AZadanieRekrutacyjneController::ServerTogglePulsing_Implementation(ALightBulb *lightBulbActor)
{
	lightBulbActor->NetMulticastTogglePulsing();
}


void AZadanieRekrutacyjneController::ServerToggleLight_Implementation(ALightBulb * lightBulbActor)
{
	lightBulbActor->NetMulticastToggleLight();
}

void AZadanieRekrutacyjneController::SetLightColour_MultiplayerHandler(FLinearColor newColor)
{
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ALightBulb * lightBulbActor = Cast<ALightBulb>(*ActorItr);
		if (IsBulbServer(lightBulbActor))
		{
			//we are server
			lightBulbActor->NetMulticastSetColor(newColor);
		}
		else if (IsBulbClient(lightBulbActor))
		{
			//we are client	
			ServerSetLightColor(lightBulbActor, newColor);
		}
	}
}

void AZadanieRekrutacyjneController::ServerSetLightColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color)
{
	lightBulbActor->NetMulticastSetColor(color);
}

