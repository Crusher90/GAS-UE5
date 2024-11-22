// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	UGAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;
	
};
