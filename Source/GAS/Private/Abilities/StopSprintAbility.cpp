// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/StopSprintAbility.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UStopSprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                         const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                         const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(const ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo()))
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = StopSprintSpeed;
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
	}
}

void UStopSprintAbility::PreActivate(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}