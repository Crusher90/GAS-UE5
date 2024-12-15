﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GProjectileBase.generated.h"

class UGameplayEffect;
class UNiagaraComponent;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class GAS_API AGProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Props|Collision")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, Category="Props|Niagara")
	UNiagaraComponent* NiagaraComp;

	UPROPERTY(VisibleAnywhere, Category="Props|Audio")
	UAudioComponent* AudioComp;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Movement")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category="Projectile|Movement")
	TSubclassOf<UGameplayEffect> OverlapEffect;

protected:
	UFUNCTION()
	void OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
