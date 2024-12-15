// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GAttackAbility.h"

#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/Character.h"

void UGAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilityAttackAbility"));
}

void UGAttackAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("ActivateAbilityPreAttackAbility"));
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}

void UGAttackAbility::SpawnProjectile()
{
	const ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo());
	if (const USkeletalMeshSocket* Socket = Character->GetMesh()->GetSocketByName(FName("SpawnProjectile")))
	{
		const FTransform SpawnTransform = Socket->GetSocketTransform(Character->GetMesh());
		if (AActor* Projectile = GetWorld()->SpawnActorDeferred<AActor>(SpawnProjectileClass, SpawnTransform,
			GetAvatarActorFromActorInfo(), nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn))
		{
			Projectile->FinishSpawning(SpawnTransform);
		}
	}
}
