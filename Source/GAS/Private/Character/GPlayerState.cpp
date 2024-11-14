// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GPlayerState.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"


AGPlayerState::AGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UGAttributeSet>("AttributeSet");
}
