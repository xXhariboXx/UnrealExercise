// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "LightBulb.h"
#include "DamagableActor.h"
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
	/** Retrun wheter lightbulb is server */
	bool IsBulbServer(ALightBulb * bulb);
	/** Retrun wheter lightbulb is client */
	bool IsBulbClient(ALightBulb * bulb);

	/** Toggle pulsing of all lightbulbs on the level */
	void TogglePulsing();
	/** Handles server pulsing toggle and sends toggle request to all actors at all clients */
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerTogglePulsing(ALightBulb *lightBulbActor);
	virtual void ServerTogglePulsing_Implementation(ALightBulb *lightBulbActor);
	virtual bool ServerTogglePulsing_Validate(ALightBulb *lightBulbActor) { return true; }

	/** Toggle light of all lightbulbs on the level */
	void ToggleLight();
	/** Handles server light toggle and sends toggle request to all actors at all clients */
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerToggleLight(ALightBulb *lightBulbActor);
	virtual void ServerToggleLight_Implementation(ALightBulb *lightBulbActor);
	virtual bool ServerToggleLight_Validate(ALightBulb *lightBulbActor) { return true; }

	/** Sets the light colour of all lightbulbs on the level to red */
	void SetLightColourRed();
	/** Sets the light colour of all lightbulbs on the level to green */
	void SetLightColourGreen();
	/** Sets the light colour of all lightbulbs on the level to blue */
	void SetLightColourBlue();
	/** Sets the light colour of all lightbulbs on the level to random generated colour */
	void SetLightColorRandom();
	/** Handles server light color change and sends new color to all actors at all clients */
	void SetLightColour_MultiplayerHandler(FLinearColor newColor);
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetLightColor(ALightBulb *lightBulbActor, FLinearColor color);
	virtual void ServerSetLightColor_Implementation(ALightBulb *lightBulbActor, FLinearColor color);
	virtual bool ServerSetLightColor_Validate(ALightBulb *lightBulbActor, FLinearColor color) { return true; }
	
};
