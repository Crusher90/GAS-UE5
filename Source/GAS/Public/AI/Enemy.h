// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GBaseCharacter.h"
#include "Interface/GEnemyInterface.h"
#include "Enemy.generated.h"

class UGEnemyWidget;
class UWidgetComponent;

UCLASS()
class GAS_API AEnemy : public AGBaseCharacter, public IGEnemyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	FVector GetEnemyStartLocation_Implementation();

protected:
	void OnEnemyHealthChanged(const float HealthToSet) const;

	void OnEnemyManaChanged(const FOnAttributeChangeData& OnAttributeChangeData) const;
	
	virtual void BeginPlay() override;

public:
	virtual void PossessedBy(AController* NewController) override;

	virtual FRotator GetViewRotation() const override;
	
	UPROPERTY(EditDefaultsOnly, Category="GAS|DamageEffect")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(VisibleAnywhere, Category="GAS|HealthManaWidget")
	UWidgetComponent* HealthManaText;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="GAS|Field")
	FVector EnemyLocation;

	virtual void Death() override;

	UPROPERTY(VisibleAnywhere, Category="GAS|HealthManaWidget")
	const UGEnemyWidget* Widget;

	virtual void EnableWeaponCollision() override;
	
	virtual void DisableWeaponCollision() override;
};
