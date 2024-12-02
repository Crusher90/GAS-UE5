// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GDodgeAbility.h"

#include "GameFramework/Character.h"


void UGDodgeAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                     const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                     const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilityDodgeAbility"));

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilityPreDodgeAbility"));
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}
