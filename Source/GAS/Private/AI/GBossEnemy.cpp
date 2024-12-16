// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GBossEnemy.h"


// Sets default values
AGBossEnemy::AGBossEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGBossEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGBossEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGBossEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

