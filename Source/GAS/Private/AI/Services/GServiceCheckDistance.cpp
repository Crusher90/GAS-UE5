// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/GServiceCheckDistance.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UGServiceCheckDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (const UWorld* World = GetWorld())
	{
		if (const ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController())
		{
			if (LocalPlayer->GetPlayerController(GetWorld()) && LocalPlayer->GetPlayerController(GetWorld())->GetPawn() && OwnerComp.GetAIOwner()->GetPawn())
			{
				const FVector PlayerLocation = LocalPlayer->GetPlayerController(GetWorld())->GetPawn()->GetActorLocation();
				const FVector EnemyLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
				const float DistanceToEnemy = (EnemyLocation - PlayerLocation).Length();
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("CanAttack"), DistanceToEnemy < MinDistance);
			}
		}
	}
}