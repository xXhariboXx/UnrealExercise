// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "LightBulb.h"
#include "ZadanieRekrutacyjneController.generated.h"

/**
 *
 */
UCLASS()
class ZADANIEREKRUTACYJNE_API AZadanieRekrutacyjneController : public APlayerController
{
	GENERATED_BODY()

public:
	AZadanieRekrutacyjneController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/** Initialize sterring input */
	virtual void SetupInputComponent() override;

private:
	/** Sets the light colour to red */
	void SetLightColourRed();
	/** Sets the light colour to green */
	void SetLightColourGreen();
	/** Sets the light colour to blue */
	void SetLightColourBlue();
	/** Sets the light colour to random generated colour */
	void SetLightColorRandom();

	bool IsBulbServer(ALightBulb * bulb);
	bool IsBulbClient(ALightBulb * bulb);


	void SetLightColour_MultiplayerHandler(FLinearColor newColor);
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetLightColor(ALightBulb *lightBulbActor, FLinearColor color);
	virtual void ServerSetLightColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color);
	virtual bool ServerSetLightColor_Validate(ALightBulb *lightBulbActor, FLinearColor color);
	UFUNCTION(Netmulticast, Reliable, WithValidation)
		void NetMulticastSetColor(ALightBulb *lightBulbActor, FLinearColor color);
	virtual void NetMulticastSetColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color);
	virtual bool NetMulticastSetColor_Validate(ALightBulb *lightBulbActor, FLinearColor color);
};
