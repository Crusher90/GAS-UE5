// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation|Attributes", meta = (AllowPrivateAccess = "true"))
	ACharacter* MyCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation|Attributes", meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation|Attributes", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation|Attributes", meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;
};
