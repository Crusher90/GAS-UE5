// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GGameOverlay.h"

#include "Components/ProgressBar.h"

void UGGameOverlay::SetHealthBarValue(float ValueToSet)
{
	PBHealth->SetPercent(ValueToSet);
}
