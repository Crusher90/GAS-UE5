// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GBaseCharacter.h"

#include "Components/GAbilitySystemComponent.h"

// Sets default values
AGBaseCharacter::AGBaseCharacter(): AbilitySystemComp(nullptr)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* AGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void AGBaseCharacter::GiveStartupAbilities()
{
	/*
	 *	Startup abilities array is filled with abilities, to activate it we require their index number
	 */
	check(AbilitySystemComp);
	if(!HasAuthority()) return;
	for(const auto StartAbility : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(StartAbility, 1);
		AbilitySystemComp->GiveAbility(AbilitySpec);
	}
}

void AGBaseCharacter::InitDefaultAttributes()
{
	const FGameplayEffectContextHandle ContextHandle = AbilitySystemComp->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComp->MakeOutgoingSpec(StartupGameplayEffect, 1.f,
		ContextHandle);
	AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

