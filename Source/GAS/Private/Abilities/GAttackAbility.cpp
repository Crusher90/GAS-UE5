// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GAttackAbility.h"

#include "Engine/SkeletalMeshSocket.h"

void UGAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UGAttackAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void UGAttackAbility::SpawnProjectile(const USkeletalMeshComponent* MeshComp) const
{
	if (const USkeletalMeshSocket* Socket = MeshComp->GetSocketByName(FName("SpawnProjectile")))
	{
		const FTransform SpawnTransform = Socket->GetSocketTransform(MeshComp);
		if (AActor* Projectile = GetWorld()->SpawnActorDeferred<AActor>(SpawnProjectileClass, SpawnTransform,
			GetAvatarActorFromActorInfo(), nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn))
		{
			Projectile->FinishSpawning(SpawnTransform);
		}
	}
}