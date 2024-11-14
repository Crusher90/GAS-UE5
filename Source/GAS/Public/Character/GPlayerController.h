// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPlayerController.generated.h"

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
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category="Player|Inputs")
	UInputAction* SprintAction;

protected:
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump(const FInputActionValue& InputActionValue);
	void StopJump(const FInputActionValue& InputActionValue);
	void Sprint(const FInputActionValue& InputActionValue);
	void StopSprint(const FInputActionValue& InputActionValue);
	void Attack(const FInputActionValue& InputActionValue);
	
public:
	UPROPERTY(VisibleAnywhere, Category="Player")
	ACharacter* MyCharacter;	
	
};
