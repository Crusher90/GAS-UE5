// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GHUD.h"

#include "Blueprint/UserWidget.h"

void AGHUD::BeginPlay()
{
	Super::BeginPlay();
	GameOverlay = CreateWidget(GetOwningPlayerController(), GameOverlayClass);
	if (GameOverlay)
	{
		GameOverlay->AddToViewport();
	}
}
