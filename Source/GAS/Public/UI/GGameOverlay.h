// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GGameOverlay.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class GAS_API UGGameOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* PBHealth;

private:
	void SetHealthBarValue(float ValueToSet);
};
