// Copyright (C) 2025 Uriel Ballinas, VOIDWARE Prohibited. All rights reserved.
// This software is licensed under the MIT License (LICENSE.md).

#include "GameplayAbilities/AlsxtGameplayFeatureAbilityDash.h"
#include "AbilitySystemComponent.h"
#include "AbilityTasks/AlsxtAbilityTaskDash.h"

/**
* @file AlsxtGameplayFeatureAbilityDash.h
* @brief Modular Dash Gameplay Ability
*/
UAlsxtGameplayFeatureAbilityDash::UAlsxtGameplayFeatureAbilityDash()
{
	// Configure ability to be instantly activated and to use an initial cost.
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerExecution;
	bRetriggerInstancedAbility = true;
}

void UAlsxtGameplayFeatureAbilityDash::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		// Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

		if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		}

		// Apply initial cost using a spec with a Set by Caller magnitude
		FGameplayEffectContextHandle EffectContext = ActorInfo->AbilitySystemComponent->MakeEffectContext();
		FGameplayEffectSpecHandle InitialCostSpecHandle = ActorInfo->AbilitySystemComponent->MakeOutgoingSpec(InitialCostEffect, 1.0f, EffectContext);
		InitialCostSpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag("SetByCaller.StaminaCost"), InitialBaseStaminaCost);
		InitialCostSpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag("SetByCaller.DashCost"), InitialBaseDashCost);
		ActorInfo->AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*InitialCostSpecHandle.Data.Get());

		// Apply continuous cost effect
		FGameplayEffectSpecHandle ContinuousCostSpecHandle = ActorInfo->AbilitySystemComponent->MakeOutgoingSpec(OngoingCostEffect, 1.0f, EffectContext);
		OngoingCostEffectHandle = ActorInfo->AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*ContinuousCostSpecHandle.Data.Get());

		// Start the Dash Ability Task
		UAlsxtAbilityTaskDash* DashTask = UAlsxtAbilityTaskDash::CreateDashTask(this, DashDuration);
		DashTask->OnFinished.AddDynamic(this, &UAlsxtGameplayFeatureAbilityDash::OnDashFinished);
		DashTask->ReadyForActivation();
	}
}

bool UAlsxtGameplayFeatureAbilityDash::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
	// Check CurrentStamina and CurrentDash against Minimum Stamina and Dash Cost
}

void UAlsxtGameplayFeatureAbilityDash::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
	CancelAbility(Handle, ActorInfo, ActivationInfo, true);
}

void UAlsxtGameplayFeatureAbilityDash::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

void UAlsxtGameplayFeatureAbilityDash::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	if (IsActive() && HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		// Clean up the ongoing cost effect
		if (OngoingCostEffectHandle.IsValid())
		{
			ActorInfo->AbilitySystemComponent->RemoveActiveGameplayEffect(OngoingCostEffectHandle);
		}
	}
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UAlsxtGameplayFeatureAbilityDash::OnDashFinished()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}
