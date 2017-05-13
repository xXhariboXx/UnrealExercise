// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/DestructibleMesh.h"
#include "Damagable.h"
#include "DamagableActor.generated.h"

UCLASS()
class ZADANIEREKRUTACYJNE_API ADamagableActor : public AActor, public IDamagable
{
	GENERATED_BODY()

private:
	/** Max health value */
	float fMaxHealth = 100;
	/** Current health value */
	float fCurrentHealth;
	/**  True when actor is dead - health <= 0 */
	bool bIsDead;

	/** Const with filepath to base component destructable mesh */
	const FString DestructableMeshPath = FString(TEXT("/Game/MyContent/Materials/Bulb_DM"));
	/** Base destructable component */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseComponent", meta = (AllowPrivateAccess = "true"))
		class UDestructibleComponent * BaseComponent;

public:
	// Sets default values for this actor's properties
	ADamagableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MyCategory")
		void HandleDamage(float fDamageValue);
	/** Implementation of IDamagable interface.
	Decrements current health by fDamage */
	virtual void HandleDamage_Implementation(float fDamage) override;

	/** Returns true if actor is dead */
	bool IsDead();
	/** Returns max health value */
	float GetMaxHealth() { return fMaxHealth; }
	/** Sets max health value */
	void SetMaxHealth(float fNewMaxHealth) { fMaxHealth = fNewMaxHealth; }
	/** Returns current health value */
	float GetCurrentHeatlh() { return fCurrentHealth; }

private:
	/** Calculates health. Decrements current health by fDamage */
	void CalculateHealth(float fDamage);
	/** Makes death action - eplodes destructible component */
	void MakeDeathAction();
};
