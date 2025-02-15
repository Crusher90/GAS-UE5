﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_API UGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data) override;

public:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_Health", Category="GAS|Attributes|Data")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Health);
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_MaxHealth", Category="GAS|Attributes|Data")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_Mana", Category="GAS|Attributes|Data")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Mana);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_MaxMana", Category="GAS|Attributes|Data")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_Stamina", Category="GAS|Attributes|Data")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Stamina);
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_MaxStamina", Category="GAS|Attributes|Data")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxStamina);
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_Experience", Category="GAS|Attributes|Data")
	FGameplayAttributeData Experience;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Experience);
	UFUNCTION()
	void OnRep_Experience(const FGameplayAttributeData& OldExperience) const;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_MaxExperience", Category="GAS|Attributes|Data")
	FGameplayAttributeData MaxExperience;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, MaxExperience);
	UFUNCTION()
	void OnRep_MaxExperience(const FGameplayAttributeData& OldMaxExperience) const;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_Level", Category="GAS|Attributes|Data")
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Level);
	UFUNCTION()
	void OnRep_Level(const FGameplayAttributeData& OldLevel) const;

	UPROPERTY(VisibleAnywhere, Category="GAS|Attributes|Data")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UGAttributeSet, Damage);
};