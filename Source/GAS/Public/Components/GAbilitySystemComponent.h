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

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="ASC|Abilities")
	TSubclassOf<UGameplayAbility> FireballAbility;
	
};
