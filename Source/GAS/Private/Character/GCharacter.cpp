// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GCharacter.h"

#include "Camera/CameraComponent.h"
#include "Character/GPlayerState.h"
#include "Components/GAbilitySystemComponent.h"
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
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();
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
	}
}

void AGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(AGPlayerState* PS = GetPlayerState<AGPlayerState>())
	{
		AbilitySystemComp = CastChecked<UGAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComp->InitAbilityActorInfo(PS, this);
	}
}


