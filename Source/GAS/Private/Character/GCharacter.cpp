// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GCharacter.h"

#include "Camera/CameraComponent.h"
#include "Character/GAttributeSet.h"
#include "Character/GPlayerState.h"
#include "Components/BoxComponent.h"
#include "Components/GAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AGCharacter::AGCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->RotationRate = FRotator(0.0f, 360.f, 0.f);
	GetCharacterMovement()->bOrientRotationToMovement = true;

	WeaponBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBoxCollision"));
	WeaponBoxCollision->SetupAttachment(GetMesh(), FName("sword_bottom"));
	WeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	WeaponBoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();

	WeaponBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnWeaponOverlap);
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetLevelAttribute()).AddUObject(this, &ThisClass::OnLevelChanged);
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetExperienceAttribute()).AddUObject(this, &ThisClass::OnExperienceChanged);
}

void AGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if(AGPlayerState* PS = GetPlayerState<AGPlayerState>())
	{
		AbilitySystemComp = PS->AbilitySystemComponent;
		AttributeSet = PS->AttributeSet;
		AbilitySystemComp->InitAbilityActorInfo(PS, this);
		if (HasAuthority())
		{
			GiveStartupAbilities();
			if(InitAttributeGameplayEffect)
			{
				InitDefaultAttributes();
			}
		}
	}
}

void AGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(AGPlayerState* PS = GetPlayerState<AGPlayerState>())
	{
		AbilitySystemComp = PS->AbilitySystemComponent;
		AttributeSet = PS->AttributeSet;
		AbilitySystemComp->InitAbilityActorInfo(PS, this);
		if (HasAuthority())
		{
			GiveStartupAbilities();
			if(InitAttributeGameplayEffect)
			{
				InitDefaultAttributes();
			}
		}
	}
}

void AGCharacter::Death()
{
	Super::Death();
	BPDied();
}

void AGCharacter::OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
			const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffectClass, 1.f, ContextHandle);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), AbilitySystemInterface->GetAbilitySystemComponent());
			const FGameplayEffectSpecHandle SpecHandle2 = GetAbilitySystemComponent()->MakeOutgoingSpec(OwnerEffectClass, 1.f, ContextHandle);
			GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle2.Data.Get());
		}
	}
}

void AGCharacter::OnExperienceChanged(const FOnAttributeChangeData& Data)
{
	if (Data.NewValue >= GetAttributeSet()->GetMaxExperience())
	{
		GetAttributeSet()->SetExperience(0.f);
		GetAttributeSet()->SetLevel(AttributeSet->GetLevel() + 1);
	}
	AbilitySystemComp->OnUIExperienceChanged.Broadcast(Data.NewValue);
}

void AGCharacter::OnLevelChanged(const FOnAttributeChangeData& Data)
{
	if (LevelUPEffectClass)
	{
		const FGameplayEffectContextHandle Handle = GetAbilitySystemComponent()->MakeEffectContext();
		const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(LevelUPEffectClass, 1.f, Handle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		AbilitySystemComp->OnUILevelChanged.Broadcast(Data.NewValue);
	}
}

FName AGCharacter::GetPlayerMontageName_Implementation()
{
	return MontageSectionName;
}

void AGCharacter::SetPlayerMontageName_Implementation(FName MontageName)
{
	MontageSectionName = MontageName;
}

void AGCharacter::EnableWeaponCollision()
{
	WeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
}

void AGCharacter::DisableWeaponCollision()
{
	WeaponBoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}
