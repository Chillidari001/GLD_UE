// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "Relic.generated.h"

UCLASS()
class GAS_API ARelic : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARelic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InteractWithMe() override;

	virtual void ShowInteractionUI() override;
	virtual void HideInteractionUI() override;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* RelicLight;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	bool IsInteracted = false;
	
private:
	UPROPERTY(EditAnywhere)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RelicMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionUI;
};
