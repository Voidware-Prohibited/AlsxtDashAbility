<h1 align="center">ALSXT Dash Ability Modular Game Feature</h1>

<p align="center">
<img src="AlsxtDashAbility.png" alt="ALSXT Dash Ability">
</p>

<p align="center">
     <a href="https://github.com/Voidware-Prohibited/AlsxtDashAbility/commits/main"><img src="https://img.shields.io/github/last-commit/Voidware-Prohibited/AlsxtDashAbility.svg?logo=github&logoColor=white" alt="GitHub last commit"></a> 
     <a href="https://github.com/Voidware-Prohibited/AlsxtDashAbility/commits/main"><img src="https://img.shields.io/github/checks-status/Voidware-Prohibited/AlsxtDashAbility/main?logo=github&logoColor=white" alt="Checks Status"></a> 
     <a href="https://github.com/Voidware-Prohibited/AlsxtDashAbility/issues"><img src="https://img.shields.io/github/issues-raw/Voidware-Prohibited/AlsxtDashAbility.svg?logo=github&logoColor=white" alt="GitHub issues"></a> 
     <a href="https://github.com/Voidware-Prohibited/AlsxtDashAbility/pulls"><img src="https://img.shields.io/github/issues-pr-raw/Voidware-Prohibited/AlsxtDashAbility.svg?logo=github&logoColor=white" alt="GitHub pull requests"></a> 
     <a href="https://github.com/Voidware-Prohibited/AlsxtDashAbility/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-MIT-silver.svg?logo=github&logoColor=white" alt="MIT License"></a>
</p>
<p align="center">
     <a href="https://github.com/sponsors/colorindarkness"><img src="https://img.shields.io/github/sponsors/colorindarkness.svg?logo=github&logoColor=white" alt="Become a Sponsor"></a> 
     <a href="https://www.patreon.com/colorindarkness"><img src="https://img.shields.io/endpoint.svg?url=https%3A%2F%2Fshieldsio-patreon.vercel.app%2Fapi%3Fusername%3Dcolorindarkness%26type%3Dpatrons" alt="Become a Patron"></a> 
     <a href="https://ko-fi.com/colorindarkness"><img alt="Support me on Ko-fi" src="https://img.shields.io/badge/support_me_on-Ko--fi-red?link=https%3A%2F%2Fko-fi.com%2Fcolorindarkness"></a> 
     <a href="https://liberapay.com/colorindarkness"><img alt="Support me on Liberapay" src="https://img.shields.io/badge/support_me_on-liberapay-yellow?link=https%3A%2F%2Fliberapay.com%2Fcolorindarkness%2F"></a>
</p>

> [!NOTE]  Following the acquisition of GitHub by Microsoft, VOIDWARE Prohibited has taken the principled acion and have begun primarily hosting our code and content on Codeberg. Mirrors will still be maintained on GitHub and GitLab.



A Dash Gameplay Ability implemented as a Modular Game Feature for  [ALSXT](https://github.com/Voidware-Prohibited/ALSXT).



> [!WARNING]  _ALSXT is under heavy development, many features may not be finished or production-ready. Use at your own risk._ 



_[Contibutors](#Contributions) and PRs are welcome_.

**Dependencies**

- [ALSXT](https://github.com/Voidware-Prohibited/ALSXT/)
- [Advanced Locomotion System Refactored](https://github.com/Sixze/ALS-Refactored/)
- [Gameplay Abilities](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/GameplayAbilities/)
- [Gameplay Targeting System](https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-targeting-system-in-unreal-engine)

# Installation

Packages while be provided when the codebase is stable. Until then, the code will need to be compiled with your IDE of choice.

- Clone this repository into the `[Project Folder]/Plugins/GameFeatures` folder
- Rebuild your Project

# Usage

Configure the IC_Dash Input Context to set the Input Key.

Grant the Gameplay Ability to the Owner.

Use the Input Action defined in IC_Dash to Activate the Gameplay Ability

# Documentation

## Gameplay Abilities

### UAlsxtGameplayFeatureDashAbility

StaminaCost

DashCost

## Input

IA_Dash

IC_Dash

## Gameplay Effects

UAlsxtGameplayEffectInitialCost

UAlsxtGameplayEffectOngoingCost

UAlsxtGameplayEffectDashRegen

## Attribute Sets

UAlsxtAttritbuteSetDash

CurrentDash

MaximumDash

CurrentDashStrength

MaximumDashStrength

CurrentDashRegen

MaximumDashRegen

Gameplay Cues

Dash Trail

## Settings

TODO

# Contributions

If you wish to contribute, please ensure you are in sync with ALSXT, message me and I'll set up permissions for you. While I try to stay in sync with ALS-Refactored, at times it may be temporarily out of sync and features may break or need refactoring.
Please submit an issue for any Compile error fixes. Most are usually the result of ALSXT not being synced to ALS-R.

# License

Original content and code in this repository is under the [MIT license](LICENSE.md). 

# Special Thanks

[Sixze](https://github.com/Sixze)

[Joseph Thigpen, Narxim](https://github.com/Narxim) for [Narxim-GAS-Example](https://github.com/Narxim/Narxim-GAS-Example)

[tranek](https://github.com/tranek) for [GASDocumentation](https://github.com/tranek/GASDocumentation)