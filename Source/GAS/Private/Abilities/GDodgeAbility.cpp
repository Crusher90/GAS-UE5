// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GDodgeAbility.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"


void UGDodgeAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                     const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                     const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if(ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo()))
	{
		const FVector LaunchVelocity = FVector(Character->GetVelocity().X, Character->GetVelocity().Y, 0.f);
		Character->LaunchCharacter(LaunchVelocity * DodgeDistance, true, false);
	}
}

void UGDodgeAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}