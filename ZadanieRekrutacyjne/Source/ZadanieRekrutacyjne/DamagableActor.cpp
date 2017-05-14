// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "DamagableActor.h"


// Sets default values
ADamagableActor::ADamagableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bReplicateMovement = true;

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

void ADamagableActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADamagableActor, fMaxHealth);
	DOREPLIFETIME(ADamagableActor, fCurrentHealth);
	DOREPLIFETIME(ADamagableActor, bIsDead);
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
	if (Role != ROLE_Authority)
	{
		//clients do damage
		ServerUpdateHealth(0.1);	//line added for easier debugging
	}
	if (bIsDead)
	{
		MakeDeathAction();
	}
}

void ADamagableActor::HandleDamage_Implementation(float fDamageValue)
{
	ServerUpdateHealth(fDamageValue);
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

void ADamagableActor::ServerUpdateHealth_Implementation(float fDamage)
{
	CalculateHealth(fDamage);
}