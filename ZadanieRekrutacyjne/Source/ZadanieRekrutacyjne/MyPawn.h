// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "LightBulb.h"
#include "MyPawn.generated.h"

UCLASS()
class ZADANIEREKRUTACYJNE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LightBulbComponents", meta = (AllowPrivateAccess = "true"))
		class ALightBulb *LightBulb;
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetLightColor(FLinearColor color);
	virtual void ServerSetLightColor_Implementation(FLinearColor color);
	virtual bool ServerSetLightColor_Validate(FLinearColor color);
	
	
};
