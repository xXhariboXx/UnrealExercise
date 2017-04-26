// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "LightBulb.h"


// Sets default values
ALightBulb::ALightBulb()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitializeComponents();
	SetupDefaultValues();
}

void ALightBulb::InitializeComponents()
{
	LightSource = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightSource"));
	LightBulbMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBulbMesh"));
	const TCHAR* link = *LightBulbMeshPath;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> LightBulbMesh(link);

	LightBulbMeshComponent->SetStaticMesh(LightBulbMesh.Object);
	LightBulbMeshComponent->SetSimulatePhysics(true);
	LightBulbMeshComponent->SetEnableGravity(true);

	LightSource->SetIntensity(fBaseIntensity);

	RootComponent = LightBulbMeshComponent;
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
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	EnableInput(PlayerController);
	SetupInput();
	SetLightColourRandom();
}

//////////////////////////////////////////////////////////////////////////
// Input Setup
void ALightBulb::SetupInput()
{
	//Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Red", IE_Pressed, this, &ALightBulb::SetLightColourRed);		//Set on 'R' keyboard button
	InputComponent->BindAction("Green", IE_Pressed, this, &ALightBulb::SetLightColourGreen);	//Set on 'G' keyboard button
	InputComponent->BindAction("Blue", IE_Pressed, this, &ALightBulb::SetLightColourBlue);		//Set on 'B' keyboard button
	InputComponent->BindAction("Rand", IE_Pressed, this, &ALightBulb::SetLightColourRandom);	//Set on 'X' keyboard button
	InputComponent->BindAction("TogglePulse", IE_Pressed, this, &ALightBulb::TogglePulsing);	//Set on 'P' keyboard button
	InputComponent->BindAction("ToggleLight", IE_Pressed, this, &ALightBulb::ToggleLight);		//Set on 'L' keyboard button
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
		LightSource->SetIntensity(LightSource->Intensity + fPulsingSpeed * fDeltaTime);
	}
	else
	{
		LightSource->SetIntensity(LightSource->Intensity - fPulsingSpeed * fDeltaTime);
	}
}

void ALightBulb::SetLightColourRed()
{
	float red = 1;
	float green = 0;
	float blue = 0;
	FLinearColor temp = LightSource->LightColor;
	FLinearColor color = FLinearColor(temp.R + red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALightBulb::SetLightColourGreen()
{
	float red = 0;
	float green = 1;
	float blue = 0;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALightBulb::SetLightColourBlue()
{
	float red = 0;
	float green = 0;
	float blue = 1;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALightBulb::SetLightColourRandom()
{
	float red = std::rand() % 1000 * 0.001f;
	float green = std::rand() % 1000 * 0.001f;
	float blue = std::rand() % 1000 * 0.001f;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALightBulb::ToggleLight()
{
	if (bIsLightSourceSwitchedOn)
	{
		LightSource->SetIntensity(0);
		bIsLightSourceSwitchedOn = false;
	}
	else
	{
		LightSource->SetIntensity(fBaseIntensity);
		bIsLightSourceSwitchedOn = true;
	}
}

void ALightBulb::TogglePulsing()
{
	if (bIsLightPulsingEnabled)
	{
		bIsLightPulsingEnabled = false;
		LightSource->SetIntensity(fBaseIntensity);
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