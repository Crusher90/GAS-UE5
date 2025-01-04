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
	UTextBlock* TBHealth;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TBStamina;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TBMana;

public:
	virtual void NativeConstruct() override;
	virtual bool Initialize() override;
	
	void HealthChanged(const FOnAttributeChangeData& Data);
	void ManaChanged(const FOnAttributeChangeData& Data);
	void StaminaChanged(const FOnAttributeChangeData& Data);
	void OnLevelChanged(const float LevelToSet);
	void OnExperienceChanged(const float ExperienceToSet);
};
