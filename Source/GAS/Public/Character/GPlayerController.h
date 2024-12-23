// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPlayerController.generated.h"

class AGCharacter;
class UInputMappingContext;
struct FInputActionValue;
class UInputAction;
/**
 * 
 */
UCLASS()
class GAS_API AGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputMappingContext* MappingContext;
	
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* IncreaseSpeedAction;

	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* DecreaseSpeedAction;

	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, Category="GAS|Player|Inputs")
	UInputAction* UltimateAction;

protected:
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump();		
	void StopJump();
	void Attack();			// build up mana on successful hits to enemy
	void Dodge();			// consume stamina
	void Ultimate();		// consume mana
	void IncreaseSpeed();
	void DecreaseSpeed();
	
public:
	UPROPERTY(VisibleAnywhere, Category="GAS|Player")
	AGCharacter* MyCharacter;

	UPROPERTY(EditAnywhere, Category="GAS|Player")
	float GameSensitivity = 45.f;
};