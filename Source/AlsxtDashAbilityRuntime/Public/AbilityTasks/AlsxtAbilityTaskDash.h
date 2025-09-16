#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AlsxtAbilityTaskDash.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDashFinished);

UCLASS()
class ALSXTDASHABILITYRUNTIME_API UAlsxtAbilityTaskDash : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAlsxtAbilityTaskDash* CreateDashTask(UGameplayAbility* OwningAbility, float DashDuration);

	UPROPERTY(BlueprintAssignable)
	FOnDashFinished OnFinished;

	virtual void Activate() override;
	virtual void OnDestroy(bool bInOwnerFinished) override;

protected:
	void OnTimerFinished();
	FTimerHandle TimerHandle;
	float DashDuration;
};
