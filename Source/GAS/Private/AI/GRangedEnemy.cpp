// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GRangedEnemy.h"

#include "Components/BoxComponent.h"


// Sets default values
AGRangedEnemy::AGRangedEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGRangedEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
