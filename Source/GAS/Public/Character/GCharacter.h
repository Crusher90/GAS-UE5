// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GBaseCharacter.h"
#include "Interface/GPlayerInterface.h"
#include "GCharacter.generated.h"

class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAS_API AGCharacter : public AGBaseCharacter, public IGPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGCharacter();

protected:
	UFUNCTION()
	void OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnRep_PlayerState() override;

	virtual void PossessedBy(AController* NewController) override;

private:
	UPROPERTY(VisibleAnywhere, Category="Properties|Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="Properties|Camera")
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, Category="Properties|Weapon")
	UBoxComponent* WeaponBoxCollision;
};
