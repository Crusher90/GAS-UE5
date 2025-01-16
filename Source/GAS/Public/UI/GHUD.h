// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GHUD.generated.h"

class UGCAWidget;
/**
 * 
 */
UCLASS()
class GAS_API AGHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category="GAS|UI|Widgets")
	UUserWidget* GUserWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GAS|UI|Widgets")
	UGCAWidget* GMainWidgetStack;
	
	UPROPERTY(EditDefaultsOnly, Category="GAS|UI|Widgets")
	TSubclassOf<UUserWidget> GMainWidgetClass;
};