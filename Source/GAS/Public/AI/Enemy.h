// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GBaseCharacter.h"
#include "Enemy.generated.h"

class UWidgetComponent;

UCLASS()
class GAS_API AEnemy : public AGBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void PossessedBy(AController* NewController) override;

	virtual FRotator GetViewRotation() const override;
	
	UPROPERTY(EditDefaultsOnly, Category="GAS|DamageEffect")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(VisibleAnywhere, Category="GAS|HealthManaWidget")
	UWidgetComponent* HealthManaBar;

	virtual void Death() override;
};
