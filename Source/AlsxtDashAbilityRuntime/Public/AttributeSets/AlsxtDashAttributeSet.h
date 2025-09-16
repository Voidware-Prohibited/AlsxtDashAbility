// Copyright (C) 2025 Uriel Ballinas, VOIDWARE Prohibited. All rights reserved.
// This software is licensed under the MIT License (LICENSE.md).

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/AttributeSets/AlsxtAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "AlsxtDashAttributeSet.generated.h"

/**
* @file AlsxtDashAttributeSet.h
* @brief Attribute Set for the Dash Gameplay Ability 
*/
UCLASS()
class ALSXTDASHABILITYRUNTIME_API UAlsxtDashAttributeSet : public UAlsxtAttributeSetBase
{
	GENERATED_BODY()

public:	
	UAlsxtDashAttributeSet();

	// Attribute Set Overrides.
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	virtual void ClampAttributes(const FGameplayAttribute& Attribute, float& NewValue) const override;

	// Set Attributes to replicate.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Holds the current value for Dash.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_CurrentDash)
	FGameplayAttributeData CurrentDash;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, CurrentDash)

	// Holds the value for Maximum Dash.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_MaximumDash)
	FGameplayAttributeData MaximumDash;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, MaximumDash)

	// Holds the current value for Dash Strength.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_CurrentDashStrength)
	FGameplayAttributeData CurrentDashStrength;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, CurrentDashStrength)

	// Holds the value for Maximum Dash Strength.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_MaximumDashStrength)
	FGameplayAttributeData MaximumDashStrength;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, MaximumDashStrength)

	// Holds the current value for Dash Regeneration.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_DashRegeneration)
	FGameplayAttributeData DashRegeneration;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, DashRegeneration)

	// Holds the value for Maximum Dash Strength.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash Attribute Set", ReplicatedUsing = OnRep_MaximumDashRegeneration)
	FGameplayAttributeData MaximumDashRegeneration;
	ATTRIBUTE_ACCESSORS_BASIC(UAlsxtDashAttributeSet, MaximumDashRegeneration)

protected:
	
	UFUNCTION()
	virtual void OnRep_CurrentDash(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaximumDash(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_CurrentDashStrength(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaximumDashStrength(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_DashRegeneration(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaximumDashRegeneration(const FGameplayAttributeData& OldValue);
};
