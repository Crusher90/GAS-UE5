// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/GPlayerInterface.h"
#include "Perception/AIPerceptionComponent.h"


// Sets default values
AGAIController::AGAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComp");
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorComp");
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>("BlackboardComp");
	bStartAILogicOnPossess = true;
}

void AGAIController::PerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Actor != nullptr && Actor->Implements<UGPlayerInterface>())
	{
		GetBlackboardComponent()->SetValueAsObject(FName("TargetActor"), Actor);
		GetBlackboardComponent()->SetValueAsBool(FName("IsAgro"), true);
	}
}

void AGAIController::PerceptionForgotten(AActor* Actor)
{
	if (Actor != nullptr && Actor->Implements<UGPlayerInterface>())
	{
		GetBlackboardComponent()->SetValueAsObject(FName("TargetActor"), nullptr);
		GetBlackboardComponent()->SetValueAsBool(FName("IsAgro"), false);
		BehaviorComp->RestartLogic();
	}
}

// Called when the game starts or when spawned
void AGAIController::BeginPlay()
{
	Super::BeginPlay();
	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::PerceptionUpdated);
	PerceptionComp->OnTargetPerceptionForgotten.AddDynamic(this, &ThisClass::PerceptionForgotten);
}