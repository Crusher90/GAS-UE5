// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GProjectileBase.h"
#include "GBurdenProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class GAS_API AGBurdenProjectile : public AGProjectileBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGBurdenProjectile();

protected:
	virtual void OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
