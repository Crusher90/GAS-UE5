// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/GProjectileBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "NiagaraComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AGProjectileBase::AGProjectileBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(FName("CollisionComp"));
	SetRootComponent(CollisionComp);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetEnableGravity(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 4000.f;
	ProjectileMovement->ProjectileGravityScale = 1.f;

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	NiagaraComp->SetupAttachment(GetRootComponent());

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComp->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AGProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnProjectileOverlap);
}

void AGProjectileBase::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		// if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		// {
		// 	const FGameplayEffectContextHandle ContextHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeEffectContext();
		// 	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeOutgoingSpec(OverlapEffect, 1.f, ContextHandle);
		// 	AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		// 	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StartCameraShake(CameraShake);
		// }
		if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(GetOwner()))
		{
			const IAbilitySystemInterface* AbilitySystemInterfaceTarget = Cast<IAbilitySystemInterface>(OtherActor);
			const FGameplayEffectContextHandle ContextHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeOutgoingSpec(OverlapEffect, 1.f, ContextHandle);
			AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), AbilitySystemInterfaceTarget->GetAbilitySystemComponent());
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StartCameraShake(CameraShake);
		}
	}
}
