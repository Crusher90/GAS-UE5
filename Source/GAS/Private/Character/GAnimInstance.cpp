// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MyCharacter = Cast<ACharacter>(TryGetPawnOwner());	
}

void UGAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(MyCharacter == nullptr)
		return;
	FVector Velocity = MyCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = MyCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = MyCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}