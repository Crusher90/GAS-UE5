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
	
	UFUNCTION()
	void OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(VisibleAnywhere, Category="Projectile|Collision")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Particle")
	UParticleSystemComponent* ParticleComp;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Movement")
	UProjectileMovementComponent* ProjectileMovement;
};
