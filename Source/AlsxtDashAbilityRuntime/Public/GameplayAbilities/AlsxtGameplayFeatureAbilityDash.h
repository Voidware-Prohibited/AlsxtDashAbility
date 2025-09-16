// Copyright (C) 2025 Uriel Ballinas, VOIDWARE Prohibited. All rights reserved.
// This software is licensed under the MIT License (LICENSE.md).

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayAbilities/AlsxtGameplayAbilityBase.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "AlsxtGameplayFeatureAbilityDash.generated.h"

struct FGameplayEventData;
struct FGameplayAbilityActorInfo;
struct FGameplayAbilitySpecHandle;
struct FGameplayAbilityActivationInfo;

/**
* @file AlsxtGameplayFeatureAbilityDash.h
* @brief Modular Dash Gameplay Ability
*/
UCLASS()
class ALSXTDASHABILITYRUNTIME_API UAlsxtGameplayFeatureAbilityDash : public UAlsxtGameplayAbilityBase
{
	GENERATED_BODY()

public:
	UAlsxtGameplayFeatureAbilityDash();

	// Set initial costs in the editor
	UPROPERTY(EditDefaultsOnly, Category = "Cost")
	float InitialBaseStaminaCost;

	UPROPERTY(EditDefaultsOnly, Category = "Cost")
	float InitialBaseDashCost;

	// Set continuous costs in the editor
	UPROPERTY(EditDefaultsOnly, Category = "Cost")
	float BaseStaminaCostPerSecond;

	UPROPERTY(EditDefaultsOnly, Category = "Cost")
	float BaseDashCostPerSecond;

	// Set the dash duration
	UPROPERTY(EditDefaultsOnly, Category = "Dash")
	float DashDuration;


protected:	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	UFUNCTION()
	void OnDashFinished();
	
	// Initial cost effect to apply instantly
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	TSubclassOf<UGameplayEffect> InitialCostEffect;

	// Ongoing cost effect applied over the dash duration
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	TSubclassOf<UGameplayEffect> OngoingCostEffect;

	// The active gameplay effect handle for the ongoing cost
	FActiveGameplayEffectHandle OngoingCostEffectHandle;
};
