// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "LightBulb.h"


// Sets default values
ALightBulb::ALightBulb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightSource = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightSource"));
	LightBulbMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticBulbMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> LightBulbMesh(TEXT("/Game/Blueprints/Bulb"));
	LightBulbMeshComponent->SetStaticMesh(LightBulbMesh.Object);
	LightBulbMeshComponent->SetSimulatePhysics(true);
	LightBulbMeshComponent->SetEnableGravity(true);

	RootComponent = LightBulbMeshComponent;
	LightSource->AttachTo(RootComponent);

	fBaseIntensity = LightSource->Intensity;
	bIsLightSourceSwitchedOn = true;
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
	InputComponent->BindAction("Red", IE_Pressed, this, &ALightBulb::SetLightColourRed);
	InputComponent->BindAction("Green", IE_Pressed, this, &ALightBulb::SetLightColourGreen);
	InputComponent->BindAction("Blue", IE_Pressed, this, &ALightBulb::SetLightColourBlue);
	InputComponent->BindAction("Rand", IE_Pressed, this, &ALightBulb::SetLightColourRandom);
	InputComponent->BindAction("LightOnOFF", IE_Pressed, this, &ALightBulb::ToggleLight);
}

// Called every frame
void ALightBulb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

////////////////////////////////////////////////////
//Light manipulation methods
void ALightBulb::SetLightColourRed()
{
	float red = 1;
	float green = 0;
	float blue = 0;
	FLinearColor color = FLinearColor(red, green, blue, 1);
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
	if (bIsLightSourceSwitchedOn == false)
	{
		LightSource->SetIntensity(fBaseIntensity);
		bIsLightSourceSwitchedOn = true;
	}
	else
	{
		LightSource->SetIntensity(0);
		bIsLightSourceSwitchedOn = false;
	}
}