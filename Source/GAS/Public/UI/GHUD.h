﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GHUD.generated.h"

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
	UPROPERTY(VisibleAnywhere, Category="UI|Widgets")
	UUserWidget* GUserWidget;

	UPROPERTY(VisibleAnywhere, Category="UI|Widgets")
	UUserWidget* GameOverlay;
	
	UPROPERTY(EditAnywhere, Category="UI|Widgets")
	TSubclassOf<UUserWidget> GameOverlayClass;
};
