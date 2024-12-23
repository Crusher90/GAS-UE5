// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GServiceCheckDistance.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGServiceCheckDistance : public UBTService
{
	GENERATED_BODY()

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere, Category="GAS|Fields")
	float MinDistance = 75.f;
};