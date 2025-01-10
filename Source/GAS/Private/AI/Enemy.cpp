// Fill out your copyright notice in the Description page of Project Settings.


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

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (AttributeSet)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("attribute set is %s"), *AttributeSet->GetName()));
	}
	if (HealthManaText)
	{
		HealthManaText->SetVisibility(true);
	}
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GetAttributeSet()->GetHealthAttribute()).AddUObject(this, &ThisClass::OnEnemyHealthChanged);
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
	// GetController()->StopMovement();
	Super::Death();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s death"), *GetName()));
}

void AEnemy::OnEnemyHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	if (Widget)
	{
		Widget->PBHealth->SetPercent(OnAttributeChangeData.NewValue / GetAttributeSet()->GetMaxHealth());
	}
}

void AEnemy::OnEnemyManaChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	if (Widget)
	{
		Widget->PBMana->SetPercent(OnAttributeChangeData.NewValue / GetAttributeSet()->GetMaxMana());
	}
}
