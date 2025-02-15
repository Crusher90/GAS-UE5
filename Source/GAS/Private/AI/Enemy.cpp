﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UI/GEnemyWidget.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UGAttributeSet>("AttributeSetG");
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	HealthManaText = CreateDefaultSubobject<UWidgetComponent>("HealthManaText");
	HealthManaText->SetupAttachment(GetMesh());
}

FVector AEnemy::GetEnemyStartLocation_Implementation()
{
	return EnemyLocation;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (HealthManaText)
	{
		HealthManaText->SetVisibility(false);
	}
	AbilitySystemComp->OnUIHealthChanged.AddUObject(this, &ThisClass::OnEnemyHealthChanged);
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GetAttributeSet()->GetManaAttribute()).AddUObject(this, &ThisClass::OnEnemyManaChanged);
	Widget = Cast<UGEnemyWidget>(HealthManaText->GetWidget());
	EnemyLocation = GetActorLocation();
}

void AEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	AbilitySystemComp->InitAbilityActorInfo(this, this);
	GiveStartupAbilities();
	if (HasAuthority())
	{
		GiveStartupAbilities();
		if(InitAttributeGameplayEffect)
		{
			InitDefaultAttributes();
		}
	}
}

FRotator AEnemy::GetViewRotation() const
{
	return GetActorRotation();
}

void AEnemy::Death()
{
	Super::Death();
}

void AEnemy::EnableWeaponCollision()
{
}

void AEnemy::DisableWeaponCollision()
{
}

void AEnemy::OnEnemyHealthChanged(const float HealthToSet) const
{
	if (Widget)
	{
		Widget->PBHealth->SetPercent(HealthToSet / GetAttributeSet()->GetMaxHealth());
	}
}

void AEnemy::OnEnemyManaChanged(const FOnAttributeChangeData& OnAttributeChangeData) const
{
	if (Widget)
	{
		Widget->PBMana->SetPercent(OnAttributeChangeData.NewValue / GetAttributeSet()->GetMaxMana());
	}
}
