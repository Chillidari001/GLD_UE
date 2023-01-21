// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASCharacter.h"
#include "InteractionInterface.h"
#include "Components/WidgetComponent.h"
#include "Collectible.generated.h"

//spelt collectable wrong in the class name and it is pissing me right off. 

UCLASS()
class GAS_API ACollectible : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InteractWithMe() override;

	virtual void ShowInteractionUI() override;
	virtual void HideInteractionUI() override;

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* PRootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CollectableMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionUI;

	UPROPERTY(EditAnywhere, Category = "Player Reference");
	AGASCharacter* PlayerCharacter;

	bool IsCollected = false;
};