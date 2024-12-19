// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/GFireballProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Mechanics/GBurdenProjectile.h"


// Sets default values
AGFireballProjectile::AGFireballProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	CollisionComp->SetEnableGravity(false);
	
	ProjectileMovement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void AGFireballProjectile::BeginPlay()
{
	Super::BeginPlay();

	CollisionComp->IgnoreActorWhenMoving(GetInstigator(), true);
	SetLifeSpan(4.f);
}

void AGFireballProjectile::SpawnProjectile(const FTransform& SpawnTransform) const
{
	AActor* Projectile = GetWorld()->SpawnActorDeferred<AGBurdenProjectile>(BurdenProjectileClass, SpawnTransform,
	GetOwner(), GetInstigator(), ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
	if(Projectile)
	{
		Projectile->FinishSpawning(SpawnTransform);
	}
}

void AGFireballProjectile::Destroyed()
{
	Super::Destroyed();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "FireballProjectileDestroyed");
	UGameplayStatics::SpawnEmitterAtLocation(this, DestroyParticle, GetActorLocation(), GetActorRotation());
	SpawnProjectile(GetActorTransform());
}