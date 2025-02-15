﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GPlayerState.generated.h"

class UGAttributeSet;
class UGAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GAS_API AGPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UPROPERTY(VisibleAnywhere, Category="GAS")
	UGAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, Category="GAS")
	UGAttributeSet* AttributeSet;
};