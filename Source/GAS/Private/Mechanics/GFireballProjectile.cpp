// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/GFireballProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Mechanics/GBurdenProjectile.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AGFireballProjectile::AGFireballProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetReplicates(true);
	SphereComp = CreateDefaultSubobject<USphereComponent>(FName("SphereComp"));
	SetRootComponent(SphereComp);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetEnableGravity(false);

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(FName("ParticleComp"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->SetIsReplicated(true);

	Location1 = CreateDefaultSubobject<USceneComponent>(FName("Location1"));
	Location1->SetupAttachment(GetRootComponent());
	Location2 = CreateDefaultSubobject<USceneComponent>(FName("Location2"));
	Location2->SetupAttachment(GetRootComponent());
	Location3 = CreateDefaultSubobject<USceneComponent>(FName("Location3"));
	Location3->SetupAttachment(GetRootComponent());
	Location4 = CreateDefaultSubobject<USceneComponent>(FName("Location4"));
	Location4->SetupAttachment(GetRootComponent());
	Location5 = CreateDefaultSubobject<USceneComponent>(FName("Location5"));
	Location5->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AGFireballProjectile::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
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
	SpawnProjectile(Location1->GetComponentTransform());
	SpawnProjectile(Location2->GetComponentTransform());
	SpawnProjectile(Location3->GetComponentTransform());
	SpawnProjectile(Location4->GetComponentTransform());
	SpawnProjectile(Location5->GetComponentTransform());
}
