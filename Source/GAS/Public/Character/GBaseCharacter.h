// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GBaseCharacter.generated.h"

class UGAttributeSet;
class UGameplayEffect;
class UGameplayAbility;
class UGAbilitySystemComponent;

UCLASS()
class GAS_API AGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UGAttributeSet* GetAttributeSet() const;

	void GiveStartupAbilities();

	void InitDefaultAttributes() const;

public:
	UPROPERTY(VisibleAnywhere, Category="Ability|Properties")
	UGAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, Category="GAS")
	UGAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category="Ability|StartupAbilities")
	TMap<FName, TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category="Ability|StartupEffect")
	TSubclassOf<UGameplayEffect> InitAttributeGameplayEffect;
};
