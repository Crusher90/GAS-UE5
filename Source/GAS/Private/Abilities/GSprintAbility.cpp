// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GSprintAbility.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGSprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilitySprintAbility"));
	if(const ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo()))
	{
		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("velocity: %f"), Character->GetVelocity().Size2D()));
		Character->GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		// const FGameplayEffectContextHandle ContextHandle = ActorInfo->AbilitySystemComponent->MakeEffectContext();
		// const FGameplayEffectSpecHandle SpecHandle = ActorInfo->AbilitySystemComponent->MakeOutgoingSpec(GameplayEffectToApply, 1.f, ContextHandle);
		// ActorInfo->AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
	}
}

void UGSprintAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilityPreSprintAbility"));
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}
