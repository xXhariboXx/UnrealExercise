// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include <ctime>
#include "LightBulb.generated.h"

UCLASS()
class ZADANIEREKRUTACYJNE_API ALightBulb : public AActor
{
	GENERATED_BODY()


private:
	/////////////////////////////////////////////////////
	//Light values
	/** Base light intensity value */
	float fBaseIntensity = 5000;
	/** True when light is switched on */
	bool bIsLightSourceSwitchedOn;

	/////////////////////////////////////////////////////
	//Pulsing values
	/** Maximim light intensity */
	float fMaxIntensity;
	/** Minimum light intensity */
	float fMinIntensity;
	/** Pulsing speed. 5000 is very fast, 500 is very slow */
	float fPulsingSpeed;
	/** True when light pulsing is enabled */
	bool bIsLightPulsingEnabled;
	/** True when light is brightning up */
	bool bIsPoolsingUp;

	//UPROPERTY(Replicated)
	float fCurrentIntensity;
	//UPROPERTY(Replicated)
	FLinearColor CurrentColour;

	/////////////////////////////////////////////////////
	//Light bulb components
	/** Const with filepath to Light Bulb mesh */
	const FString LightBulbMeshPath = FString(TEXT("/Game/MyContent/Materials/Bulb"));
	/** Light Bulb mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LightBulbComponents", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent *LightBulbMeshComponent;
	/** Point Light component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LightBulbComponents", meta = (AllowPrivateAccess = "true"))
		class UPointLightComponent *LightSource;

public:
	// Sets default values for this actor's properties
	ALightBulb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Return the LightBulb mesh*/
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return LightBulbMeshComponent; }
	/** Returns base intensity value */
	float GetBaseIntensity() { return fBaseIntensity; }
	/** Returns if light is switched on */
	bool IsLightSourceSwitchedOn() { return bIsLightSourceSwitchedOn; }
	/** Returns maximum light intensity */
	float GetMaxIntensity() { return fMaxIntensity; }
	/** Sets maximum light intensity */
	void SetMaxIntensity(float fmax) { fMaxIntensity = fmax; }
	/** Returns minimum light intensity */
	float GetMMinIntensity() { return fMinIntensity; }
	/** Sets maximum light intensity */
	void SetMMinIntensity(float fmin) { fMinIntensity = fmin; }
	/** Returns pulsing speed */
	float GetPulsingSpeed() { return fPulsingSpeed; }
	/** Sets pulsing speed */
	void SetPulsingSpeed(float fSpeed) { fPulsingSpeed = fSpeed; }
	/** Toggle pulsing */
	void TogglePulsing();
	/** Toggles light */
	void ToggleLight();

private:
	/** Initializes components */
	void InitializeComponents();
	/** Sets default values to fields */
	void SetupDefaultValues();
	/** Initialize sterring input */
	void SetupInput();

	/** Method that decides if pulse light */
	void LightPulsing(float fDeltaTime);
	/** Method that makes light pulsing */
	void Pulsing(float fDeltaTime);
	/** Retrun wheter light can or can'y pulse */
	bool CanPulse();
	/** Sets the light colour to red */
	void SetLightColourRed();
	//UFUNCTION(reliable, server, WithValidation)
	/** Sets the light colour to green */
	void SetLightColourGreen();
	/** Sets the light colour to blue */
	void SetLightColourBlue();
	/** Sets the light colour to random generated colour */
	void SetLightColorRandom();

	void SetLightColour_MultiplayerHandler(FLinearColor newColor);
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetLightColor(FLinearColor color);
	virtual void ServerSetLightColor_Implementation(FLinearColor color);
	virtual bool ServerSetLightColor_Validate(FLinearColor color);
	UFUNCTION(Netmulticast, Unreliable, WithValidation)
		void NetMulticastSetColor(FLinearColor color);
	virtual void NetMulticastSetColor_Implementation(FLinearColor color);
	virtual bool NetMulticastSetColor_Validate(FLinearColor color);
};
