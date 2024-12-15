// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GProjectileBase.h"
#include "GFireballProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class GAS_API AGFireballProjectile : public AGProjectileBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGFireballProjectile();

	virtual void Destroyed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnProjectile(const FTransform& SpawnTransform) const;

private:
	UPROPERTY(EditAnywhere, Category="Projectile|Spawn")
	TSubclassOf<AActor> BurdenProjectileClass;

	UPROPERTY(EditAnywhere, Category="Projectile|Spawn")
	UParticleSystem* DestroyParticle;
};
