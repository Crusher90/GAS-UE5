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
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputMappingContext* MappingContext;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* UltimateAction;

protected:
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump();		
	void StopJump();
	void Sprint();			// consume stamina
	void StopSprint();
	void Attack();			// build up mana on successful hits to enemy
	void Dodge();			// consume stamina
	void Ultimate();		// consume mana
	
public:
	UPROPERTY(VisibleAnywhere, Category="Player")
	AGCharacter* MyCharacter;

	UPROPERTY(EditAnywhere, Category="Player")
	float GameSensitivity = 45.f;
};
