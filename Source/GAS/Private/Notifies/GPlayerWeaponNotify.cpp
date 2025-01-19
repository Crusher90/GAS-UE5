// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifies/GPlayerWeaponNotify.h"

#include "Interface/GPlayerInterface.h"

void UGPlayerWeaponNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                       float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (IGPlayerInterface* PlayerInterface = Cast<IGPlayerInterface>(MeshComp->GetOwner()))
	{
		PlayerInterface->EnableWeaponCollision();
	}
}

void UGPlayerWeaponNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (IGPlayerInterface* PlayerInterface = Cast<IGPlayerInterface>(MeshComp->GetOwner()))
	{
		PlayerInterface->DisableWeaponCollision();
	}
}