// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy.h"

#include "Character/GAttributeSet.h"
#include "Components/GAbilitySystemComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


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

	HealthManaBar = CreateDefaultSubobject<UWidgetComponent>("HealthManaBar");
	HealthManaBar->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (AttributeSet)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("attribute set is %s"), *AttributeSet->GetName()));
	}
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