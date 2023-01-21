// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible.h"

// Sets default values
ACollectible::ACollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = PRootComponent;

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collectable Mesh"));
	CollectableMesh->SetupAttachment(RootComponent);

	InteractionUI=CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction UI"));
	InteractionUI->SetupAttachment(RootComponent);

	InteractionUI->SetVisibility(false);
}

// Called when the game starts or when spawned
void ACollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectible::InteractWithMe()
{
	if(IsCollected == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Porter interacted with"));
		PlayerCharacter->CollectableCount++;
		CollectableMesh->SetVisibility(false);
		CollectableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		IsCollected = true;	
	}
}

void ACollectible::ShowInteractionUI()
{
	if(IsCollected == false)
	{
		InteractionUI->SetVisibility(true);
	}
}

void ACollectible::HideInteractionUI()
{
	InteractionUI->SetVisibility(false);
}

