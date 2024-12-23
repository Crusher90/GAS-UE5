// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GUserWidget.h"

#include "Character/GBaseCharacter.h"

bool UGUserWidget::Initialize()
{
	if(!Super::Initialize())
		return false;
	BaseCharacter = Cast<AGBaseCharacter>(GetOwningPlayerPawn());
	if (BaseCharacter)
	{
		ASComp = BaseCharacter->AbilitySystemComp;
		ASet = BaseCharacter->AttributeSet;
	}
	return true;
}