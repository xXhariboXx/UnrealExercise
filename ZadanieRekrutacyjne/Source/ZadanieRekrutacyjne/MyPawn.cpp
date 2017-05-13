// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "MyPawn.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LightBulb = CreateDefaultSubobject<ALightBulb>(TEXT("LightBulb"));
	LightBulb->SetOwner(this);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ServerSetLightColor(FLinearColor(1,1,1,1));

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawn::ServerSetLightColor_Implementation(FLinearColor color)
{
	UE_LOG(LogTemp, Warning, TEXT("cokolwiek"));
}

bool AMyPawn::ServerSetLightColor_Validate(FLinearColor color)
{
	return true;
}

