// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/GCAWidget.h"
#include "UI/GUserWidget.h"

void AGHUD::BeginPlay()
{
	Super::BeginPlay();
	GUserWidget = CreateWidget(GetOwningPlayerController(), UGUserWidget::StaticClass());
	if(GUserWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("main user widget is %s"), *GUserWidget->GetName()));
	}
	GMainWidgetStack = Cast<UGCAWidget>(CreateWidget(GetOwningPlayerController(), GMainWidgetClass));
	if (GMainWidgetStack)
	{
		GMainWidgetStack->AddToViewport();
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("main user Stack is %s"), *GUserWidget->GetName()));
	}
}