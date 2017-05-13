// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "DamagableActor.h"


// Sets default values
ADamagableActor::ADamagableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
	BaseComponent = CreateDefaultSubobject<UDestructibleComponent>(TEXT("BaseComponent"));
	const TCHAR* link = *DestructableMeshPath;
	static ConstructorHelpers::FObjectFinder<UDestructibleMesh> BaseComponentMesh(link);

	if (BaseComponentMesh.Succeeded())
	{
		BaseComponent->SetDestructibleMesh(BaseComponentMesh.Object);
	}

	RootComponent = BaseComponent;

	bIsDead = false;
	fCurrentHealth = fMaxHealth;
}

// Called when the game starts or when spawned
void ADamagableActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADamagableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateHealth(1);	//line added for easier debugging
	if (bIsDead)
	{
		MakeDeathAction();
	}
}

void ADamagableActor::HandleDamage_Implementation(float fDamageValue)
{
	CalculateHealth(fDamageValue);
}

void ADamagableActor::CalculateHealth(float fDamage)
{
	fCurrentHealth -= fDamage;
	if (fCurrentHealth <= 0)
	{
		bIsDead = true;
	}
	else if (fCurrentHealth > fMaxHealth)
	{
		fCurrentHealth = fMaxHealth;
	}
}

bool ADamagableActor::IsDead()
{
	return bIsDead;
}

void ADamagableActor::MakeDeathAction()
{
	BaseComponent->ApplyDamage(250, GetActorLocation(), GetActorLocation(), 0.0f);
}
