// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GAbilitySystemComponent.h"

#include "Character/GAttributeSet.h"
#include "Character/GBaseCharacter.h"

UGAbilitySystemComponent::UGAbilitySystemComponent()
{
	SetIsReplicated(true);
}

void UGAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	GetGameplayAttributeValueChangeDelegate(UGAttributeSet::GetHealthAttribute()).AddUObject(this, &ThisClass::HealthChanged);
}

void UGAbilitySystemComponent::HealthChanged(const FOnAttributeChangeData& Data) const
{
	if (GetNumericAttribute(UGAttributeSet::GetHealthAttribute()) == 0.f)
	{
		if (AGBaseCharacter* BaseChar = Cast<AGBaseCharacter>(GetAvatarActor()))
		{
			BaseChar->Death();
		}
	}
	OnUIHealthChanged.Broadcast(GetNumericAttribute(UGAttributeSet::GetHealthAttribute()));
}