// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/GUserWidget.h"

void AGHUD::BeginPlay()
{
	Super::BeginPlay();
	GUserWidget = CreateWidget(GetOwningPlayerController(), UGUserWidget::StaticClass());
	if(GUserWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("main user widget is %s"), *GUserWidget->GetName()));
	}
	GameOverlay = CreateWidget(GetOwningPlayerController(), GameOverlayClass);
	if (GameOverlay)
	{
		GameOverlay->AddToViewport();
	}
}
