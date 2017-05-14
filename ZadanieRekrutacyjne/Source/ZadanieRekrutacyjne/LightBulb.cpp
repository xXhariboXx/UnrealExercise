// Fill out your copyright notice in the Description page of Project Settings.

#include "ZadanieRekrutacyjne.h"
#include "LightBulb.h"


// Sets default values
ALightBulb::ALightBulb()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
	//HoldingActor->AttachRootComponentToActor(this);
	//this->SetOwner(this);
	//this->SetOwner();
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
	PlayerController = GetWorld()->GetFirstPlayerController();
	EnableInput(PlayerController);
	SetupInput();

	//for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	//{
	//	if (Iterator->Get()->IsLocalPlayerController())
	//	{
	//		//SetOwner(Iterator->Get());
	//		PlayerController = Iterator->Get();
	//		SetOwner(PlayerController);
	//		break;
	//	}
	//}
	//if (Role == ROLE_Authority)
	//{
	//SetOwner(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	//SetLightColorRandom();
	//}
	//GetNetOwner()->GetName().GetCharArray().GetData();
	//SetOwner(PlayerController);
	//NetMulticastSetColor(FLinearColor(1, 0, 0, 1));
}

//////////////////////////////////////////////////////////////////////////
// Input Setup
void ALightBulb::SetupInput()
{
	//Set up gameplay key bindings
	check(InputComponent);
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
		fCurrentIntensity = LightSource->Intensity + fPulsingSpeed * fDeltaTime;
		LightSource->SetIntensity(fCurrentIntensity);
	}
	else
	{
		fCurrentIntensity = LightSource->Intensity - fPulsingSpeed * fDeltaTime;
		LightSource->SetIntensity(fCurrentIntensity);
	}
}



//void ALightBulb::SetLightColour_MultiplayerHandler(FLinearColor newColor)
//{
//	if (Role == ROLE_Authority)
//	{
//		//we are server
//		UE_LOG(LogTemp, Warning, TEXT("Server is calling to clients"));
//		NetMulticastSetColor(newColor);
//	}
//	else
//	{
//		//we are client	
//		//UE_LOG(LogTemp, Warning, TEXT("Client changed colour"));
//		//LightSource->SetLightColor(newColor, true);
//		UE_LOG(LogTemp, Warning, TEXT("Client calling for server"));
//		ServerSetLightColor(newColor);
//	}
//}

//void ALightBulb::ServerSetLightColor_Implementation(FLinearColor color)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Server called from client"));
//	if (Role == ROLE_Authority)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Server changing colour"));
//		//LightSource->SetLightColor(color, true);
//		UE_LOG(LogTemp, Warning, TEXT("Server calling for clients"));
//		NetMulticastSetColor(color);
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("defuq"));
//	}
//}
//
//bool ALightBulb::ServerSetLightColor_Validate(FLinearColor color)
//{
//	return true;
//}
//
//void ALightBulb::NetMulticastSetColor_Implementation(FLinearColor color)
//{
//	//UE_LOG(LogTemp, Warning, TEXT("Owner name is %s"), *GetNetOwner()->GetName());
//	UE_LOG(LogTemp, Warning, TEXT("Server executing clients"));
//	LightSource->SetLightColor(color, true);
//}
//
//bool ALightBulb::NetMulticastSetColor_Validate(FLinearColor color)
//{
//	return true;
//}

void ALightBulb::ToggleLight()
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

void ALightBulb::TogglePulsing()
{
	if (bIsLightPulsingEnabled)
	{
		fCurrentIntensity = fBaseIntensity;
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