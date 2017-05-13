// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Damagable.generated.h"

UINTERFACE(BlueprintType)
class ZADANIEREKRUTACYJNE_API UDamagable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ZADANIEREKRUTACYJNE_API IDamagable
{
	GENERATED_IINTERFACE_BODY()

public:
	//classes using this interface must implement ReactToHighNoon
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
		void HandleDamage(float fDamageValue);
};