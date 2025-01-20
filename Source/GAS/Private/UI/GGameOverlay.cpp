// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGameOverlay.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UGGameOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	if(ASComp)
	{
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetManaAttribute()).AddUObject(this, &ThisClass::ManaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetStaminaAttribute()).AddUObject(this, &ThisClass::StaminaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetMaxStaminaAttribute()).AddUObject(this, &ThisClass::MaxStaminaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::MaxHealthChanged);
		ASComp->OnUIHealthChanged.AddUObject(this, &ThisClass::HealthChanged);
		ASComp->OnUILevelChanged.AddUObject(this, &ThisClass::OnLevelChanged);
		ASComp->OnUIExperienceChanged.AddUObject(this, &ThisClass::OnExperienceChanged);
	}
}

bool UGGameOverlay::Initialize()
{
	return Super::Initialize();
}

void UGGameOverlay::ManaChanged(const FOnAttributeChangeData& Data)
{
	if (PBMana)
	{
		PBMana->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxManaAttribute()));
	}
}

void UGGameOverlay::StaminaChanged(const FOnAttributeChangeData& Data)
{
	if (PBStamina)
	{
		PBStamina->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxStaminaAttribute()));
	}
}

void UGGameOverlay::HealthChanged(const float HealthToSet)
{
	PBHealth->SetPercent(HealthToSet/ASComp->GetNumericAttribute(ASet->GetMaxHealthAttribute()));
}

void UGGameOverlay::OnLevelChanged(const float LevelToSet)
{
	TBExperience->SetText(FText::AsNumber(LevelToSet));
}

void UGGameOverlay::OnExperienceChanged(const float ExperienceToSet)
{
	PBExperience->SetPercent(ExperienceToSet/ASComp->GetNumericAttribute(ASet->GetMaxExperienceAttribute()));
}

void UGGameOverlay::MaxStaminaChanged(const FOnAttributeChangeData& Data)
{
	PBStamina->SetPercent(ASComp->GetNumericAttribute(ASet->GetStaminaAttribute()) / Data.NewValue);
}

void UGGameOverlay::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	PBHealth->SetPercent(ASComp->GetNumericAttribute(ASet->GetHealthAttribute()) / Data.NewValue);
}