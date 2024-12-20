// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GEnemyTeleportAbility.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UGEnemyTeleportAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                             const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                             const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (const AActor* Enemy = GetAvatarActorFromActorInfo())
	{
		if (AAIController* Controller = Cast<AAIController>(Enemy->GetInstigatorController()))
		{
			const FVector TargetLocation = Controller->GetBlackboardComponent()->GetValueAsVector(FName("TargetLocation"));
			GetAvatarActorFromActorInfo()->TeleportTo(TargetLocation, Enemy->GetActorRotation());
			EndAbility(Handle, ActorInfo, ActivationInfo, false, true);
		}
	}
}

void UGEnemyTeleportAbility::PreActivate(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}