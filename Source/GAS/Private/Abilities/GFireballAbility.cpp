// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GFireballAbility.h"

#include "Engine/SkeletalMeshSocket.h"
#include "Mechanics/GFireballProjectile.h"

void UGFireballAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                        const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                        const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("UGFireballAbility::ActivateAbilityFireballAbility"));
	if(const USkeletalMeshSocket* SpawnSocket = ActorInfo->GetAnimInstance()->GetSkelMeshComponent()->GetSocketByName(FName("ProjectileSpawnSocket")))
	{
		const FTransform SocketTransform = SpawnSocket->GetSocketTransform(ActorInfo->GetAnimInstance()->GetSkelMeshComponent());
		AActor* Projectile = GetWorld()->SpawnActorDeferred<AGFireballProjectile>(ProjectileClass, SocketTransform, GetOwningActorFromActorInfo(),
		Cast<APawn>(ActorInfo->AvatarActor.Get()), ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
		if(Projectile)
		{
			Projectile->FinishSpawning(SocketTransform);
		}
	}
}

void UGFireballAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData)
{
	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString("UGFireballAbility::PreActivateFireballAbility"));
	CommitAbility(Handle, ActorInfo, ActivationInfo);
}
