// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GCharacter.h"

#include "Camera/CameraComponent.h"
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
}

// Called every frame
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if(AGPlayerState* PS = GetPlayerState<AGPlayerState>())
	{
		AbilitySystemComp = CastChecked<UGAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComp->InitAbilityActorInfo(PS, this);
		if(InitAttributeGameplayEffect)
		{
			InitDefaultAttributes();
		}
	}
}

void AGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(AGPlayerState* PS = GetPlayerState<AGPlayerState>())
	{
		AbilitySystemComp = CastChecked<UGAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComp->InitAbilityActorInfo(PS, this);
		GiveStartupAbilities();
		if(InitAttributeGameplayEffect)
		{
			InitDefaultAttributes();
		}
	}
}

void AGCharacter::OnWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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