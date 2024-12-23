// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
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
	UFUNCTION()
	void PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	
	UFUNCTION()
	void PerceptionForgotten(AActor* Actor);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="GAS|AI|Properties")
	UAIPerceptionComponent* PerceptionComp;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GAS|AI|Properties")
	UBehaviorTreeComponent* BehaviorComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GAS|AI|Properties")
	UBlackboardComponent* BlackboardComp;
};