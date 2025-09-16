// Copyright (C) 2025 Uriel Ballinas, VOIDWARE Prohibited. All rights reserved.
// This software is licensed under the MIT License (LICENSE.md).

#include "AttributeSets/AlsxtDashAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Data/AlsxtDashAbilityGameplayTags.h"
#include "Net/UnrealNetwork.h"


/**
* @file AlsxtDashAttributeSet.cpp
* @brief Attribute Set for the Dash Gameplay Ability 
*/
UAlsxtDashAttributeSet::UAlsxtDashAttributeSet()
{
	MaximumDash = 1.0f;
	CurrentDash = 1.0f;
	MaximumDashStrength = 1.0f;
	CurrentDashStrength = 1.0f;
	DashRegeneration = 0.0f;
	MaximumDashRegeneration = 0.0f;
}

void UAlsxtDashAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue,	float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	
	if (Attribute == GetCurrentDashAttribute())
	{
		CheckMaxReachedForAttribute(MaximumDash, AlsxtDashAbilityTags::State::TAG_State_Max_Dash.GetTag(), NewValue);
		return;
		
	}

	if (Attribute == GetMaximumDashAttribute())
	{
		AdjustAttributeForMaxChange(GetCurrentDashAttribute(), OldValue, NewValue);
		return;
	}

	if (Attribute == GetCurrentDashStrengthAttribute())
	{
		CheckMaxReachedForAttribute(MaximumDashStrength, AlsxtDashAbilityTags::State::TAG_State_Max_DashStrength.GetTag(), NewValue);
		return;
	}

	if (Attribute == GetMaximumDashStrengthAttribute())
	{
		AdjustAttributeForMaxChange(GetCurrentDashStrengthAttribute(), OldValue, NewValue);
		return;
	}

	if (Attribute == GetDashRegenerationAttribute())
	{
		CheckMaxReachedForAttribute(MaximumDashRegeneration, AlsxtDashAbilityTags::State::TAG_State_Max_Dash.GetTag(), NewValue);
		return;
	}

	if (Attribute == GetMaximumDashRegenerationAttribute())
	{
		AdjustAttributeForMaxChange(GetDashRegenerationAttribute(), OldValue, NewValue);
		return;
	}
}

void UAlsxtDashAttributeSet::ClampAttributes(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::ClampAttributes(Attribute, NewValue);
	
	if (Attribute == GetCurrentDashAttribute())
	{
		// This should be removed in favor of another method, as we're modifying 2 times the current Dash. (One right before post, one right after (here).
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaximumDash());
		return;
	}

	if (Attribute == GetDashRegenerationAttribute())
	{
		NewValue = FMath::Max(0.f, NewValue);
		return;
	}
}

void UAlsxtDashAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams Params{};
	Params.bIsPushBased = true;
	Params.Condition = COND_None;

	// Replicated to all
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, CurrentDash, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, MaximumDash, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, CurrentDashStrength, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, MaximumDashStrength, Params);

	// Owner Only
	Params.Condition = COND_OwnerOnly;
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, DashRegeneration, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UAlsxtDashAttributeSet, MaximumDashRegeneration, Params);
}

void UAlsxtDashAttributeSet::OnRep_CurrentDash(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, CurrentDash, OldValue);
}

void UAlsxtDashAttributeSet::OnRep_MaximumDash(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, MaximumDash, OldValue);
}

void UAlsxtDashAttributeSet::OnRep_CurrentDashStrength(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, CurrentDashStrength, OldValue);
}

void UAlsxtDashAttributeSet::OnRep_MaximumDashStrength(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, MaximumDashStrength, OldValue);
}

void UAlsxtDashAttributeSet::OnRep_DashRegeneration(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, DashRegeneration, OldValue);
}

void UAlsxtDashAttributeSet::OnRep_MaximumDashRegeneration(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAlsxtDashAttributeSet, MaximumDashRegeneration, OldValue);
}




