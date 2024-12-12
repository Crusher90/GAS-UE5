// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/GEnemyWeaponNotify.h"

#include "AI/GCloseRangedEnemy.h"
#include "Components/BoxComponent.h"

void UGEnemyWeaponNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                      float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (const AGCloseRangedEnemy* Enemy = Cast<AGCloseRangedEnemy>(MeshComp->GetOwner()))
	{
		Enemy->LWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
		Enemy->RWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	}
}

void UGEnemyWeaponNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (const AGCloseRangedEnemy* Enemy = Cast<AGCloseRangedEnemy>(MeshComp->GetOwner()))
	{
		Enemy->LWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
		Enemy->RWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	}
}
