// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GPlayerState.generated.h"

class UGAttributeSet;
class UGAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GAS_API AGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AGPlayerState();
	
public:
	UPROPERTY()
	UGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UGAttributeSet* AttributeSet;
};
