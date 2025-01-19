// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GPlayerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAS_API IGPlayerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FName GetPlayerMontageName();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetPlayerMontageName(FName MontageName);
	
	virtual void EnableWeaponCollision() = 0;
	
	virtual void DisableWeaponCollision() = 0;
};
