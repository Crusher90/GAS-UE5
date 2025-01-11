// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GUserWidget.h"
#include "GGameOverlay.generated.h"

class UTextBlock;
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
	UProgressBar* PBExperience;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TBExperience;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBHealth;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBStamina;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBMana;

public:
	virtual void NativeConstruct() override;
	virtual bool Initialize() override;
	
	void ManaChanged(const FOnAttributeChangeData& Data);
	void StaminaChanged(const FOnAttributeChangeData& Data);
	void HealthChanged(const float HealthToSet);
	void OnLevelChanged(const float LevelToSet);
	void OnExperienceChanged(const float ExperienceToSet);
};
