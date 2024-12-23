// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GCloseRangedEnemy.generated.h"

class UBoxComponent;

UCLASS()
class GAS_API AGCloseRangedEnemy : public AEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGCloseRangedEnemy();

protected:
	UFUNCTION()
	void WeaponLOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void WeaponROverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category="GAS|Properties|Weapon")
	UBoxComponent* LWeaponBoxCollision;

	UPROPERTY(VisibleAnywhere, Category="GAS|Properties|Weapon")
	UBoxComponent* RWeaponBoxCollision;
};
