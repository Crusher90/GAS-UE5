// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/GBurdenProjectile.h"

#include "AI/Enemy.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AGBurdenProjectile::AGBurdenProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetReplicates(true);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	
	ProjectileMovement->bIsHomingProjectile = true;
	ProjectileMovement->HomingAccelerationMagnitude = 4000.f;
}

// Called when the game starts or when spawned
void AGBurdenProjectile::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("instigator is %s"), *GetInstigator()->GetName()));
	ProjectileMovement->HomingTargetComponent = GetInstigator()->GetRootComponent();
}

void AGBurdenProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, FString::Printf(TEXT("OverlappedHits: %d"), Hits));
	// Super::OnProjectileOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	// CollisionComp->GetOverlappingActors(OverlappedActors, AEnemy::StaticClass());
	// for (AActor* OverlappedActor : OverlappedActors)
	// {
	// 		
	// }
	const TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = {};
	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), 200.f, ObjectTypes,
		AEnemy::StaticClass(), {}, OverlappedActors);
	for (const auto Actor : OverlappedActors)
	{
		Super::OnProjectileOverlap(OverlappedComponent, Actor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}