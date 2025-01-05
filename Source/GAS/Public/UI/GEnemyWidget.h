// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GEnemyWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GAS_API UGEnemyWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TBHealth;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TBMana;
};
