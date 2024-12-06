// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UGAttributeSet>("AttributeSet");
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	GiveStartupAbilities();
	if(InitAttributeGameplayEffect)
	{
		InitDefaultAttributes();
	}
}
