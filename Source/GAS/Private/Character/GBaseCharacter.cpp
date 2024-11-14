// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GBaseCharacter.h"

#include "Components/GAbilitySystemComponent.h"

// Sets default values
AGBaseCharacter::AGBaseCharacter(): AbilitySystemComp(nullptr)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* AGBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

