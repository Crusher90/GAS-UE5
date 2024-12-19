// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "Bonfire.generated.h"

class UGameplayEffect;
class UBoxComponent;
class UCapsuleComponent;
class UNiagaraComponent;

UCLASS()
class GAS_API ABonfire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABonfire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	USceneComponent* SceneComp;
	
	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	UStaticMeshComponent* BonfireMesh;
	
	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	UNiagaraComponent* BonfireParticle;

	UPROPERTY(VisibleAnywhere, Category="Bonfire|Properties")
	UAudioComponent* BonfireSound;

	UPROPERTY(EditAnywhere, Category="Bonfire|Properties")
	TSubclassOf<UGameplayEffect> BonfireHealEffect;

	UPROPERTY(EditAnywhere, Category="Bonfire|Properties")
	TSubclassOf<UGameplayEffect> BonfireDamageEffect;

	UPROPERTY(EditAnywhere, Category="Bonfire|Properties")
	TSubclassOf<UGameplayEffect> RemoveDamageEffect;

	UPROPERTY(EditAnywhere, Category="Bonfire|Properties")
	TSubclassOf<UGameplayEffect> RemoveHealEffect;

	FActiveGameplayEffectHandle ActiveBonfireHealEffect;
	FActiveGameplayEffectHandle ActiveBonfireDamageEffect;

protected:
	UFUNCTION()
	void OnOverlapCapsule(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnOverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnEndOverlapCapsule(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UFUNCTION()
	void OnEndOverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};

