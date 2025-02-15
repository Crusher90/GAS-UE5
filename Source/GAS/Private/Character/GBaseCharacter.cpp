// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GBaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/GAbilitySystemComponent.h"

// Sets default values
AGBaseCharacter::AGBaseCharacter(): AbilitySystemComp(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
}

UAbilitySystemComponent* AGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

UGAttributeSet* AGBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AGBaseCharacter::GiveStartupAbilities()
{
	check(AbilitySystemComp);
	if(!HasAuthority()) return;
	for(const auto StartAbility : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(StartAbility.Value, 1);
		AbilitySystemComp->GiveAbility(AbilitySpec);
	}
}

void AGBaseCharacter::InitDefaultAttributes() const
{
	const FGameplayEffectContextHandle ContextHandle = AbilitySystemComp->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComp->MakeOutgoingSpec(InitAttributeGameplayEffect,
		StartupEffectLevel,ContextHandle);
	AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AGBaseCharacter::Death()
{
	GetMesh()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	SetLifeSpan(5.f);
}