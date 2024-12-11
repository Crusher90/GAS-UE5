// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GCloseRangedEnemy.h"

#include "AbilitySystemComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AGCloseRangedEnemy::AGCloseRangedEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LWeaponBoxCollision = CreateDefaultSubobject<UBoxComponent>("LeftWeaponBoxCollision");
	LWeaponBoxCollision->SetupAttachment(GetMesh(), FName("weapon_l"));
	LWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	LWeaponBoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	LWeaponBoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	RWeaponBoxCollision = CreateDefaultSubobject<UBoxComponent>("RightWeaponBoxCollision");
	RWeaponBoxCollision->SetupAttachment(GetMesh(), FName("weapon_r"));
	RWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	RWeaponBoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	RWeaponBoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void AGCloseRangedEnemy::WeaponLOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const FGameplayEffectContextHandle ContextHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffectClass, 1.f, ContextHandle);
			AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void AGCloseRangedEnemy::WeaponROverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const FGameplayEffectContextHandle ContextHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = AbilitySystemInterface->GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffectClass, 1.f, ContextHandle);
			AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

// Called when the game starts or when spawned
void AGCloseRangedEnemy::BeginPlay()
{
	Super::BeginPlay();
	LWeaponBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::WeaponLOverlap);
	RWeaponBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::WeaponROverlap);
}

// Called every frame
void AGCloseRangedEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

