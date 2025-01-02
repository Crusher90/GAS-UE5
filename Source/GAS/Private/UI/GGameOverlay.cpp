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
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetHealthAttribute()).AddUObject(this, &ThisClass::HealthChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetManaAttribute()).AddUObject(this, &ThisClass::ManaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetStaminaAttribute()).AddUObject(this, &ThisClass::StaminaChanged);
		ASComp->GetGameplayAttributeValueChangeDelegate(ASet->GetExperienceAttribute()).AddUObject(this, &ThisClass::ExperienceChanged);
	}
}

bool UGGameOverlay::Initialize()
{
	return Super::Initialize();
}

void UGGameOverlay::HealthChanged(const FOnAttributeChangeData& Data)
{
	if (TBHealth)
	{
		TBHealth->SetText(FText::AsNumber(Data.NewValue));
	}
}

void UGGameOverlay::ManaChanged(const FOnAttributeChangeData& Data)
{
	if (TBMana)
	{
		TBMana->SetText(FText::AsNumber(Data.NewValue));
	}
}

void UGGameOverlay::StaminaChanged(const FOnAttributeChangeData& Data)
{
	if (TBStamina)
	{
		TBStamina->SetText(FText::AsNumber(Data.NewValue));
	}
}

void UGGameOverlay::ExperienceChanged(const FOnAttributeChangeData& Data)
{
	if (Data.NewValue > ASComp->GetNumericAttribute(ASet->GetMaxExperienceAttribute()))
	{
		ASComp->SetNumericAttributeBase(ASet->GetExperienceAttribute(), 0.f);
		TBExperience->SetText(FText::AsNumber(++ExperienceValue));
	}
	PBExperience->SetPercent(Data.NewValue/ASComp->GetNumericAttribute(ASet->GetMaxExperienceAttribute()));
}