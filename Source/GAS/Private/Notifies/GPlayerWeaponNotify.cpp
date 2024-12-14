// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/GPlayerWeaponNotify.h"

#include "Character/GCharacter.h"
#include "Components/BoxComponent.h"

void UGPlayerWeaponNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                       float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (const AGCharacter* Player = Cast<AGCharacter>(MeshComp->GetOwner()))
	{
		Player->WeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	}
}

void UGPlayerWeaponNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (const AGCharacter* Player = Cast<AGCharacter>(MeshComp->GetOwner()))
	{
		Player->WeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	}
}
