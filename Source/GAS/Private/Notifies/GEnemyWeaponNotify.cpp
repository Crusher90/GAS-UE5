// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/GEnemyWeaponNotify.h"

#include "Interface/GEnemyInterface.h"


void UGEnemyWeaponNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                      float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (IGEnemyInterface* EnemyInterface = Cast<IGEnemyInterface>(MeshComp->GetOwner()))
	{
		EnemyInterface->EnableWeaponCollision();
	}
}

void UGEnemyWeaponNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (IGEnemyInterface* EnemyInterface = Cast<IGEnemyInterface>(MeshComp->GetOwner()))
	{
		EnemyInterface->DisableWeaponCollision();
	}
}