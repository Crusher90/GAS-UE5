// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GCloseRangedEnemy.h"

#include "AbilitySystemComponent.h"
#include "Character/GAttributeSet.h"
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
	
	RWeaponBoxCollision = CreateDefaultSubobject<UBoxComponent>("RightWeaponBoxCollision");
	RWeaponBoxCollision->SetupAttachment(GetMesh(), FName("weapon_r"));
	RWeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	RWeaponBoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void AGCloseRangedEnemy::WeaponLOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffectClass,
				1.f, ContextHandle);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),
				AbilitySystemInterface->GetAbilitySystemComponent());
			
			const FGameplayEffectContextHandle ContextHandle2 = GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle2 = GetAbilitySystemComponent()->MakeOutgoingSpec(OwnerEffectClass,
				1.f, ContextHandle2);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle2.Data.Get());
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
			const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffectClass,
				1.f, ContextHandle);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),
				AbilitySystemInterface->GetAbilitySystemComponent());
			
			const FGameplayEffectContextHandle ContextHandle2 = GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle2 = GetAbilitySystemComponent()->MakeOutgoingSpec(OwnerEffectClass,
				1.f, ContextHandle2);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle2.Data.Get());
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