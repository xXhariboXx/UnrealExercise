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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LightBulb", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent *LightBulbMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LightBulb", meta = (AllowPrivateAccess = "true"))
		class UPointLightComponent *LightSource;

	/** Base light intensity value */
	float fBaseIntensity;
	/** True when light is switched on */
	bool bIsLightSourceSwitchedOn;

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

private:
	/** Initialize sterring input */
	void SetupInput();

	/** Sets the light colour to red */
	void SetLightColourRed();
	/** Sets the light colour to green */
	void SetLightColourGreen();
	/** Sets the light colour to blue */
	void SetLightColourBlue();
	/** Sets the light colour to random generated colour */
	void SetLightColourRandom();
	/** Toggles light */
	void ToggleLight();
};
