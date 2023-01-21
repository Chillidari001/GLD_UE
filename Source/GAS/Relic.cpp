// Fill out your copyright notice in the Description page of Project Settings.


#include "Relic.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARelic::ARelic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;
	RelicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Relic Mesh"));
	RelicMesh->SetupAttachment(RootComponent);

	InteractionUI=CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction UI"));
	InteractionUI->SetupAttachment(RootComponent);

	RelicLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Relic Light"));
	RelicLight->SetupAttachment(RootComponent);
	
	InteractionUI->SetVisibility(false);
}

// Called when the game starts or when spawned
void ARelic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARelic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARelic::InteractWithMe()
{
	if(IsInteracted == false)
	{
		RelicLight->SetIntensity(900000);
		RelicLight->SetLightColor(FColor(227, 10,27));
		RelicMesh->SetVisibility(false);
		RelicMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		UE_LOG(LogTemp, Warning, TEXT("Relic interacted with"));
		IsInteracted = true;
	}
}

void ARelic::ShowInteractionUI()
{
	if(IsInteracted == false)
	{
		InteractionUI->SetVisibility(true);
	}
}

void ARelic::HideInteractionUI()
{
	InteractionUI->SetVisibility(false);
}
