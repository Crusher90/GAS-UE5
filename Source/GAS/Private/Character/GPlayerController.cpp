// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GPlayerController.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "Character/GCharacter.h"
#include "EnhancedInputSubsystems.h"

void AGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(InputComponent))
	{
		InputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		InputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
		InputComp->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Jump);
		InputComp->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJump);
		InputComp->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ThisClass::Attack);
		InputComp->BindAction(IncreaseSpeedAction, ETriggerEvent::Triggered, this, &ThisClass::IncreaseSpeed);
		InputComp->BindAction(DecreaseSpeedAction, ETriggerEvent::Completed, this, &ThisClass::DecreaseSpeed);
		InputComp->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &ThisClass::Dodge);
		InputComp->BindAction(UltimateAction, ETriggerEvent::Triggered, this, &ThisClass::Ultimate);
	}
}

void AGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<AGCharacter>(GetPawn());
	if (MyCharacter)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void AGPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (MyCharacter)
	{
		MyCharacter->AddMovementInput(ForwardDirection, MoveVector.Y);
		MyCharacter->AddMovementInput(RightDirection, MoveVector.X);
	}
}

void AGPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookVector = InputActionValue.Get<FVector2D>();
	if(MyCharacter)
	{
		MyCharacter->AddControllerYawInput( GameSensitivity * LookVector.X * GetWorld()->GetDeltaSeconds());
		MyCharacter->AddControllerPitchInput(GameSensitivity * LookVector.Y * GetWorld()->GetDeltaSeconds());
	}
}

void AGPlayerController::Jump()
{
	if(MyCharacter)
	{
		MyCharacter->Jump();
	}
}

void AGPlayerController::StopJump()
{
	if(MyCharacter)
	{
		MyCharacter->StopJumping();
	}
}

void AGPlayerController::Attack()
{
	MyCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(*MyCharacter->StartupAbilities.Find(FName("AttackAbility")));
}

void AGPlayerController::Dodge()
{
	MyCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(*MyCharacter->StartupAbilities.Find(FName("DodgeAbility")));
}

void AGPlayerController::Ultimate()
{
	MyCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(*MyCharacter->StartupAbilities.Find(FName("UltimateAbility")));
}

void AGPlayerController::IncreaseSpeed()
{
	if(MyCharacter->GetVelocity().Size2D() > 0.f)
	{
		MyCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(*MyCharacter->StartupAbilities.Find(FName("SprintAbility")));
	}
}

void AGPlayerController::DecreaseSpeed()
{
	MyCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(*MyCharacter->StartupAbilities.Find(FName("StopSprintAbility")));
}