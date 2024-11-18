// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/Bonfire.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "NiagaraComponent.h"

// Sets default values
ABonfire::ABonfire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BonfireMesh = CreateDefaultSubobject<UStaticMeshComponent>("BonfireMesh");
	SetRootComponent(BonfireMesh);
	BonfireMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	BonfireMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	CapsuleComp->SetupAttachment(GetRootComponent());
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	BoxComp = CreateDefaultSubobject<UBoxComponent>("Box");
	BoxComp->SetupAttachment(GetRootComponent());
	BoxComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	BonfireParticle = CreateDefaultSubobject<UNiagaraComponent>("Bonfire Particle");
	BonfireParticle->SetupAttachment(GetRootComponent());
	BonfireParticle->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	BonfireParticle->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts or when spawned
void ABonfire::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapCapsule);
	CapsuleComp->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlapCapsule);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBox);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlapBox);
	
}

// Called every frame
void ABonfire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonfire::OnOverlapCapsule(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		if(const IAbilitySystemInterface* Interface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			UAbilitySystemComponent* AbilitySystemComp = Interface->GetAbilitySystemComponent();
			const FGameplayEffectSpecHandle DamageEffectSpecHandle = AbilitySystemComp->
			MakeOutgoingSpec(BonfireDamageEffect,1.f, AbilitySystemComp->MakeEffectContext());
			AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*DamageEffectSpecHandle.Data);
		}
	}
}

void ABonfire::OnOverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		if(const IAbilitySystemInterface* Interface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			UAbilitySystemComponent* AbilitySystemComp = Interface->GetAbilitySystemComponent();
			const FGameplayEffectSpecHandle HealEffectSpecHandle = AbilitySystemComp->
			MakeOutgoingSpec(BonfireHealEffect,1.f, AbilitySystemComp->MakeEffectContext());
			AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*HealEffectSpecHandle.Data);
		}
	}
}

/**
 * @todo remove gameplay effect with the use of tags.
 */
void ABonfire::OnEndOverlapCapsule(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		if(const IAbilitySystemInterface* Interface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			UAbilitySystemComponent* AbilitySystemComp = Interface->GetAbilitySystemComponent();
			const FGameplayEffectSpecHandle RemoveDamageEffectSpecHandle = AbilitySystemComp->
			MakeOutgoingSpec(RemoveDamageEffect,1.f, AbilitySystemComp->MakeEffectContext());
			AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*RemoveDamageEffectSpecHandle.Data);
		}
	}
}

/**
 * @todo remove gameplay effect with the use of tags.
 */
void ABonfire::OnEndOverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		if(const IAbilitySystemInterface* Interface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			UAbilitySystemComponent* AbilitySystemComp = Interface->GetAbilitySystemComponent();
			const FGameplayEffectSpecHandle RemoveHealEffectSpecHandle = AbilitySystemComp->
			MakeOutgoingSpec(RemoveHealEffect,1.f, AbilitySystemComp->MakeEffectContext());
			AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*RemoveHealEffectSpecHandle.Data);
		}
	}
}

