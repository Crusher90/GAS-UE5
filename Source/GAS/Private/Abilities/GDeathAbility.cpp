// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GDeathAbility.h"

#include "AbilitySystemComponent.h"

void UGDeathAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                     const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                     const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	/*
	 * @todo
	 * do simulate physics and handle death;
	 */
	// const AGBaseCharacter* BaseChar = Cast<AGBaseCharacter>(GetAvatarActorFromActorInfo());
	// if (BaseChar)
	// {
	// 	BaseChar->GetMesh()->SetSimulatePhysics(true);
	// 	BaseChar->GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	// 	BaseChar->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	// 	BaseChar->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	// }
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UGDeathAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
}
