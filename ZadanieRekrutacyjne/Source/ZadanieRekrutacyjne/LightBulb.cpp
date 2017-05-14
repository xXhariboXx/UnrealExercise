// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "LightBulb.h"


// Sets default values
ALightBulb::ALightBulb()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bReplicateMovement = true;

	InitializeComponents();
	SetupDefaultValues();
}

void ALightBulb::InitializeComponents()
{
	LightSource = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightSource"));
	LightBulbMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBulbMesh"));
	const TCHAR* link = *LightBulbMeshPath;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> LightBulbMesh(link);
	if (LightBulbMesh.Succeeded())
	{
		LightBulbMeshComponent->SetStaticMesh(LightBulbMesh.Object);
	}
	LightBulbMeshComponent->SetSimulatePhysics(true);
	LightBulbMeshComponent->SetEnableGravity(true);

	LightSource->SetIntensity(fBaseIntensity);

	this->RootComponent = LightBulbMeshComponent;
	LightSource->AttachTo(RootComponent);
}

void ALightBulb::SetupDefaultValues()
{
	bIsLightSourceSwitchedOn = true;
	bIsLightPulsingEnabled = true;
	fMaxIntensity = fBaseIntensity;
	fMinIntensity = fBaseIntensity / 10;
	fPulsingSpeed = 2500;
}

// Called when the game starts or when spawned
void ALightBulb::BeginPlay()
{
	Super::BeginPlay();
	srand(time(NULL));
}

// Called every frame
void ALightBulb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LightPulsing(DeltaTime);
}

////////////////////////////////////////////////////
//Light manipulation methods
void ALightBulb::LightPulsing(float fDeltaTime)
{
	if (CanPulse())
	{
		Pulsing(fDeltaTime);
	}
}

void  ALightBulb::Pulsing(float fDeltaTime)
{
	if (LightSource->Intensity > fMaxIntensity)
	{
		bIsPoolsingUp = false;
	}
	else if (LightSource->Intensity < fMinIntensity)
	{
		bIsPoolsingUp = true;
	}

	if (bIsPoolsingUp)
	{
		fCurrentIntensity = LightSource->Intensity + fPulsingSpeed * fDeltaTime;
		LightSource->SetIntensity(fCurrentIntensity);
	}
	else
	{
		fCurrentIntensity = LightSource->Intensity - fPulsingSpeed * fDeltaTime;
		LightSource->SetIntensity(fCurrentIntensity);
	}
}

FLinearColor ALightBulb::GetRandomColor()
{
	float red = std::rand() % 1000 * 0.001f;
	float green = std::rand() % 1000 * 0.001f;
	float blue = std::rand() % 1000 * 0.001f;
	return FLinearColor(red, green, blue, 1);
}

void ALightBulb::NetMulticastSetColor_Implementation(FLinearColor color)
{
	LightSource->SetLightColor(color, true);
}

void ALightBulb::NetMulticastToggleLight_Implementation()
{
	if (bIsLightSourceSwitchedOn)
	{
		fCurrentIntensity = 0;
		LightSource->SetIntensity(fCurrentIntensity);
		bIsLightSourceSwitchedOn = false;
	}
	else
	{
		fCurrentIntensity = fBaseIntensity;
		LightSource->SetIntensity(fCurrentIntensity);
		bIsLightSourceSwitchedOn = true;
	}
}

void ALightBulb::NetMulticastTogglePulsing_Implementation()
{
	if (bIsLightPulsingEnabled)
	{
		bIsLightPulsingEnabled = false;
		LightSource->SetIntensity(fCurrentIntensity);
	}
	else
	{
		bIsLightPulsingEnabled = true;
	}
}

bool ALightBulb::CanPulse()
{
	return bIsLightSourceSwitchedOn && bIsLightPulsingEnabled;
}