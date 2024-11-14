// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GBaseCharacter.h"
#include "GCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAS_API AGCharacter : public AGBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGCharacter();

protected:
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
};
