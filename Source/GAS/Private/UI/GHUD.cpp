// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/GCAWidget.h"
#include "UI/GUserWidget.h"

void AGHUD::BeginPlay()
{
	Super::BeginPlay();
	GUserWidget = CreateWidget(GetOwningPlayerController(), UGUserWidget::StaticClass());
	GMainWidgetStack = Cast<UGCAWidget>(CreateWidget(GetOwningPlayerController(), GMainWidgetClass));
	if (GMainWidgetStack)
	{
		GMainWidgetStack->AddToViewport();
	}
}