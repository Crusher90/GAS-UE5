// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAS_API IGEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FVector GetEnemyStartLocation();
	
	virtual void EnableWeaponCollision() = 0;
	
	virtual void DisableWeaponCollision() = 0;
};
