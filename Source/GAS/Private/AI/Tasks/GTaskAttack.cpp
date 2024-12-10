// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/GTaskAttack.h"

#include "AbilitySystemComponent.h"
#include "AIController.h"
#include "Character/GBaseCharacter.h"

EBTNodeResult::Type UGTaskAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AGBaseCharacter* Enemy = Cast<AGBaseCharacter>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if (Enemy->GetAbilitySystemComponent()->TryActivateAbilityByClass(*Enemy->StartupAbilities.Find(("EnemyAttackAbility"))))
		{
			return Super::ExecuteTask(OwnerComp, NodeMemory);
		}
	}
	return EBTNodeResult::Failed;
}
