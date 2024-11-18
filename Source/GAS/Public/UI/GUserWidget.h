// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GUserWidget.generated.h"

class UGAttributeSet;
class UGAbilitySystemComponent;
class AGPlayerState;
/**
 * 
 */
UCLASS()
class GAS_API UGUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Widget|Properties")
	AGPlayerState* PState;

	UPROPERTY(VisibleAnywhere, Category="Widget|Properties")
	UGAbilitySystemComponent* ASComp;

	UPROPERTY(VisibleAnywhere, Category="Widget|Properties")
	UGAttributeSet* ASet;

public:
	virtual bool Initialize() override;
};
