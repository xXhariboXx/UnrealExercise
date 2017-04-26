// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "Lamp.h"


// Sets default values
ALamp::ALamp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);
	LightSource = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightSource"));
	BulbDestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>(TEXT("BulbDestructibleComponent"));
	//BulbStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulbUStaticMeshComponent"));
	//BulbDestructibleComponent->SetDestructibleMesh(BulbDestructibleMesh);
	//BulbDestructibleComponent->CanEditSimulatePhysics = true;


	if (GEngine)
	{
		if (BulbDestructibleComponent->CanEditSimulatePhysics())
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("moze"));
		else
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("nie moze"));
	}

	//BulbDestructibleComponent->WakeRigidBody(NAME_None);

	BulbDestructibleComponent->bComponentUseFixedSkelBounds = true;
	BulbDestructibleComponent->SetSimulatePhysics(true);
	BulbDestructibleComponent->SetEnableGravity(true);
	//BulbStaticMesh->SetSimulatePhysics(true);
	BulbDestructibleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BulbDestructibleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_MAX);

	RootComponent = BulbDestructibleComponent;
	LightSource->AttachTo(RootComponent);
	//BulbStaticMesh->AttachTo(RootComponent);

	fBaseIntensity = LightSource->Intensity;
	bIsLightSourceActive = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALamp::SetupInput()
{
	//Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Red", IE_Pressed, this, &ALamp::SetLightColourRed);
	InputComponent->BindAction("Green", IE_Pressed, this, &ALamp::SetLightColourGreen);
	InputComponent->BindAction("Blue", IE_Pressed, this, &ALamp::SetLightColourBlue);
	InputComponent->BindAction("Rand", IE_Pressed, this, &ALamp::SetLightColourRandom);
	InputComponent->BindAction("LightOnOFF", IE_Pressed, this, &ALamp::SwitchLight);
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();
	BulbDestructibleComponent->WakeRigidBody(NAME_None);
	BulbDestructibleComponent->SetSimulatePhysics(true);
	srand(time(NULL));
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	EnableInput(PlayerController);
	SetupInput();
	SetLightColourRandom();
	//BulbDestructibleComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	//BulbDestructibleComponent->SetSimulatePhysics(true);

	//if (BulbDestructibleComponent->IsSimulatingPhysics())
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Symuluje"));
	//else
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("nie"));

	//BulbDestructibleComponent->SetEnableGravity(false);
	//BulbDestructibleComponent->WakeRigidBody(NAME_None);
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);/*
	BulbDestructibleComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	BulbDestructibleComponent->SetSimulatePhysics(true);

	if (BulbDestructibleComponent->IsSimulatingPhysics())
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Symuluje"));
	else
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("nie"));

	BulbDestructibleComponent->SetEnableGravity(false);*/
}

void ALamp::SetLightColourRed()
{
	float red = 1;
	float green = 0;
	float blue = 0;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALamp::SetLightColourGreen()
{
	float red = 0;
	float green = 1;
	float blue = 0;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALamp::SetLightColourBlue()
{
	float red = 0;
	float green = 0;
	float blue = 1;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALamp::SetLightColourRandom()
{
	float red = std::rand() % 1000 * 0.001f;
	float green = std::rand() % 1000 * 0.001f;
	float blue = std::rand() % 1000 * 0.001f;
	FLinearColor color = FLinearColor(red, green, blue, 1);
	LightSource->SetLightColor(color, true);
}

void ALamp::SwitchLight()
{
	if (bIsLightSourceActive == false)
	{
		LightSource->SetIntensity(fBaseIntensity);
		bIsLightSourceActive = true;
	}
	else
	{
		LightSource->SetIntensity(0);
		bIsLightSourceActive = false;
	}
}

