// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GAbilitySystemComponent.h"

UGAbilitySystemComponent::UGAbilitySystemComponent()
{
	SetIsReplicated(true);
}

void UGAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	// const FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(FireballAbility, 1);
	// const FGameplayAbilitySpecHandle AbilitySpecHandle = GiveAbility(AbilitySpec);
	// TryActivateAbility(AbilitySpecHandle);
}
