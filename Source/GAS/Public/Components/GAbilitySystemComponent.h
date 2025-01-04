// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GAbilitySystemComponent.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUILevelChangedSignature, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnUIExperienceChangedSignature, float);

UCLASS()
class GAS_API UGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	UGAbilitySystemComponent();

	FOnUILevelChangedSignature OnUILevelChanged;
	FOnUIExperienceChangedSignature OnUIExperienceChanged;

protected:
	virtual void BeginPlay() override;
};
