// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GBaseCharacter.h"
#include "Interface/GPlayerInterface.h"
#include "GCharacter.generated.h"

class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAS_API AGCharacter : public AGBaseCharacter, public IGPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGCharacter();

protected:
	UFUNCTION()
	void OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnExperienceChanged(const FOnAttributeChangeData& Data);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void OnRep_PlayerState() override;

	virtual void PossessedBy(AController* NewController) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS|Properties|Func")
	void BPDied();
	
	virtual void Death() override;

	virtual void OnLevelChanged(const FOnAttributeChangeData& Data);

	virtual FName GetPlayerMontageName_Implementation() override;

	virtual void SetPlayerMontageName_Implementation(FName MontageName) override;

	virtual void EnableWeaponCollision() override;

	virtual void DisableWeaponCollision() override;

private:
	UPROPERTY(VisibleAnywhere, Category="GAS|Properties|Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="GAS|Properties|Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Properties|GameplayEffect")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

public:
	UPROPERTY(VisibleAnywhere, Category="GAS|Properties|Weapon")
	UBoxComponent* WeaponBoxCollision;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Ability")
	TSubclassOf<UGameplayEffect> LevelUPEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="GAS|Ability")
	FName MontageSectionName = FName("Attack1");
};