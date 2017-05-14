// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "ZadanieRekrutacyjneGameModeBase.h"

AZadanieRekrutacyjneGameModeBase::AZadanieRekrutacyjneGameModeBase()
	:
	AGameModeBase()
{
	PlayerControllerClass = AZadanieRekrutacyjneController::StaticClass();
}