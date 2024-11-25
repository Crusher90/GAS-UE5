// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/GFireballProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AGFireballProjectile::AGFireballProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComp = CreateDefaultSubobject<USphereComponent>(FName("SphereComp"));
	SetRootComponent(SphereComp);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	SphereComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(FName("ParticleComp"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.f;
}

// Called when the game starts or when spawned
void AGFireballProjectile::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnProjectileOverlap);
	
}

void AGFireballProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("otheractor is %s"), *OtherActor->GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("instigator is %s"), *GetInstigator()->GetName()));
		// UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor)->ApplyGameplayEffectSpecToSelf(); @todo how to apply gameplay effect to enemies.
		
		
		Destroy();
	}
}

void AGFireballProjectile::Destroyed()
{
	Super::Destroyed();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "FireballProjectileDestroyed");
}
