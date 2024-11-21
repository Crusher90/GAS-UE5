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
		InputComp->BindAction(SprintAction, ETriggerEvent::Triggered, this, &ThisClass::Sprint);
		InputComp->BindAction(SprintAction, ETriggerEvent::Completed, this, &ThisClass::StopSprint);
	}
}

void AGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = CastChecked<AGCharacter>(GetPawn());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
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

void AGPlayerController::Jump(const FInputActionValue& InputActionValue)
{
	if(MyCharacter)
	{
		MyCharacter->Jump();
	}
}

void AGPlayerController::StopJump(const FInputActionValue& InputActionValue)
{
	if(MyCharacter)
	{
		MyCharacter->StopJumping();
	}
}

void AGPlayerController::Sprint(const FInputActionValue& InputActionValue)
{
}

void AGPlayerController::StopSprint(const FInputActionValue& InputActionValue)
{
}

void AGPlayerController::Attack(const FInputActionValue& InputActionValue)
{
	MyCharacter->PlayMontage(MyCharacter->AttackMontage);
}
