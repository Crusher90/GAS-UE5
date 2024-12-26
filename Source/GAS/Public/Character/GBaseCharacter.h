// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GBaseCharacter.generated.h"

class UGAttributeSet;
class UGameplayEffect;
class UGameplayAbility;
class UGAbilitySystemComponent;

UCLASS()
class GAS_API AGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGBaseCharacter();
	
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UGAttributeSet* GetAttributeSet() const;

	void GiveStartupAbilities();

	void InitDefaultAttributes() const;

	virtual void Death();

public:
	UPROPERTY(VisibleAnywhere, Category="GAS|Ability|Properties")
	UGAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, Category="GAS|Ability|Properties")
	UGAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Ability|StartupAbilities")
	TMap<FName, TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Ability|StartupEffect")
	TSubclassOf<UGameplayEffect> InitAttributeGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Ability|StartupEffect")
	TSubclassOf<UGameplayEffect> OwnerEffectClass;
};