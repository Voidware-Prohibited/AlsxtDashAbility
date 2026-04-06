// Copyright (C) 2025 Uriel Ballinas, VOIDWARE Prohibited. All rights reserved.
// This software is licensed under the MIT License (LICENSE.md).

#include "Data/AlsxtDashAbilityGameplayTags.h"
#include "NativeGameplayTags.h"

/**
* @file AlsxtDashAbilityGameplayTags.cpp
* @brief Gameplay Tags for the Dash Gameplay Ability
*/
namespace AlsxtAbilityGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Dash, TEXT("Gameplay.Ability.Dash"))
}

namespace AlsxtGASGameplayTags
{
	namespace StaminaCost
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_StaminaCost_Infinite_Dash, "StaminaCost.Infinite.Dash", "A Gameplay Tag applied to Dash Stamina Cost")
		
	}
	namespace Statuses
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_State_Movement_Dash, "State.Movement.Dash", "Owned when user is in Dash gait")
	}
}

namespace AlsxtDashAbilityTags
{
	namespace State
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_State_Max_Dash, "State.Max.Dash", "Max Dash reached")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_State_Blocked_Regen_Dash, "State.Blocked.Regeneration.Dash", "Block Dash regeneration.")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_State_Max_DashStrength, "State.Max.DashStrength", "Max Dash Strength reached")
	}
}