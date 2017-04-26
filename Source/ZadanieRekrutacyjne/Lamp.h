// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/DestructibleMesh.h"
#include <ctime>
#include "Lamp.generated.h"

UCLASS()
class ZADANIEREKRUTACYJNE_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lamp", meta = (AllowPrivateAccess = "true"))
	class UDestructibleComponent * BulbDestructibleComponent;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lamp", meta = (AllowPrivateAccess = "true"))
	//class UStaticMeshComponent * BulbStaticMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lamp", meta = (AllowPrivateAccess = "true"))
	class UPointLightComponent * LightSource;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupInput();


	float fBaseIntensity;
	bool bIsLightSourceActive;

	void SetLightColourRed();
	void SetLightColourGreen();
	void SetLightColourBlue();
	void SetLightColourRandom();
	void SwitchLight();	
};
