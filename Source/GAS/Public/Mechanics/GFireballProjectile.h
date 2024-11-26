// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GFireballProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class GAS_API AGFireballProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGFireballProjectile();

	virtual void Destroyed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnProjectile(const FTransform& SpawnTransform);

private:
	UPROPERTY(VisibleAnywhere, Category="Projectile|Collision")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Particle")
	UParticleSystemComponent* ParticleComp;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Movement")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Scene")
	USceneComponent* Location1;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Scene")
	USceneComponent* Location2;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Scene")
	USceneComponent* Location3;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Scene")
	USceneComponent* Location4;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Scene")
	USceneComponent* Location5;

	UPROPERTY(EditAnywhere, Category="Projectile|Spawn")
	TSubclassOf<AActor> BurdenProjectileClass;
};
