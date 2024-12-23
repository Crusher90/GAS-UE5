// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GUserWidget.generated.h"

class AGBaseCharacter;
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
	UPROPERTY(VisibleAnywhere, Category="GAS|Widget|Properties")
	AGBaseCharacter* BaseCharacter;

	UPROPERTY(VisibleAnywhere, Category="GAS|Widget|Properties")
	UGAbilitySystemComponent* ASComp;

	UPROPERTY(VisibleAnywhere, Category="GAS|Widget|Properties")
	UGAttributeSet* ASet;

public:
	virtual bool Initialize() override;
};
