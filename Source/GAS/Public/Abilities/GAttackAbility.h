﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	/** Actually activate ability, do not call this directly */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	/** Do boilerplate init stuff and then call ActivateAbility */
	virtual void PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate,
		const FGameplayEventData* TriggerEventData = nullptr) override;

	UFUNCTION(BlueprintCallable, Category = "GAS|Events")
	void SpawnProjectile(const USkeletalMeshComponent* MeshComp) const;

	UPROPERTY(EditDefaultsOnly, Category = "GAS|Events")
	TSubclassOf<AActor> SpawnProjectileClass;
};