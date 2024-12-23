// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GUserWidget.h"
#include "GGameOverlay.generated.h"

struct FOnAttributeChangeData;
class UProgressBar;

/**
 * 
 */
UCLASS()
class GAS_API UGGameOverlay : public UGUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBHealth;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBMana;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBStamina;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBExperience;

public:
	virtual void NativeConstruct() override;
	virtual bool Initialize() override;
	
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);
	void StaminaChanged(const FOnAttributeChangeData& Data);
	void MaxStaminaChanged(const FOnAttributeChangeData& Data);
	void ExperienceChanged(const FOnAttributeChangeData& Data);
	void MaxExperienceChanged(const FOnAttributeChangeData& Data);
};
