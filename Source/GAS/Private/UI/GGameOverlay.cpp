// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGameOverlay.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"
#include "Components/ProgressBar.h"

void UGGameOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	if(ASComp)
	{
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetHealthAttribute()).AddUObject(this, &ThisClass::HealthChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::MaxHealthChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetManaAttribute()).AddUObject(this, &ThisClass::ManaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetMaxManaAttribute()).AddUObject(this, &ThisClass::MaxManaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetStaminaAttribute()).AddUObject(this, &ThisClass::StaminaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetMaxStaminaAttribute()).AddUObject(this, &ThisClass::MaxStaminaChanged);
	}
}

bool UGGameOverlay::Initialize()
{
	return Super::Initialize();
}

void UGGameOverlay::HealthChanged(const FOnAttributeChangeData& Data)
{
	PBHealth->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxHealthAttribute()));
}

void UGGameOverlay::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	PBHealth->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxHealthAttribute()));
}

void UGGameOverlay::ManaChanged(const FOnAttributeChangeData& Data)
{
	PBMana->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxManaAttribute()));
}

void UGGameOverlay::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	PBMana->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxManaAttribute()));
}

void UGGameOverlay::StaminaChanged(const FOnAttributeChangeData& Data)
{
	PBStamina->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxStaminaAttribute()));
}

void UGGameOverlay::MaxStaminaChanged(const FOnAttributeChangeData& Data)
{
	PBStamina->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxStaminaAttribute()));
}

void UGGameOverlay::ExperienceChanged(const FOnAttributeChangeData& Data)
{
	PBExperience->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxExperienceAttribute()));
}

void UGGameOverlay::MaxExperienceChanged(const FOnAttributeChangeData& Data)
{
	PBExperience->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxExperienceAttribute()));
}