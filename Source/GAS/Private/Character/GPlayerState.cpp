// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GPlayerState.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"


AGPlayerState::AGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UGAttributeSet>("AttributeSet");
	SetReplicates(true);
	NetUpdateFrequency = 60.0f;
}

UAbilitySystemComponent* AGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGPlayerState::BeginPlay()
{
	Super::BeginPlay();
}
