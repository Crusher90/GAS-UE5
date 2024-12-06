﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "GAIController.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class GAS_API AGAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category="AI|Properties")
	UAIPerceptionComponent* PerceptionComp;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Properties")
	UBehaviorTreeComponent* BehaviorComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Properties")
	UBlackboardComponent* BlackboardComp;
};
