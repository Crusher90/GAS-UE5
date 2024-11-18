// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GUserWidget.h"

#include "Character/GAttributeSet.h"
#include "Character/GPlayerState.h"
#include "Components/GAbilitySystemComponent.h"

bool UGUserWidget::Initialize()
{
	if(!Super::Initialize())
		return false;
	PState = Cast<AGPlayerState>(GetOwningPlayerState());
	if (PState)
	{
		ASComp = PState->AbilitySystemComponent;
		ASet = PState->AttributeSet;
	}
	return true;
}
