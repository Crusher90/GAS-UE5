// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GAIController.h"

#include "Perception/AIPerceptionComponent.h"


// Sets default values
AGAIController::AGAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComp");
}

// Called when the game starts or when spawned
void AGAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

