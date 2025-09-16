#include "AbilityTasks/AlsxtAbilityTaskDash.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

UAlsxtAbilityTaskDash* UAlsxtAbilityTaskDash::CreateDashTask(UGameplayAbility* OwningAbility, float InDashDuration)
{
	UAlsxtAbilityTaskDash* MyTask = NewAbilityTask<UAlsxtAbilityTaskDash>(OwningAbility);
	MyTask->DashDuration = InDashDuration;
	return MyTask;
}

void UAlsxtAbilityTaskDash::Activate()
{
	ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
	if (!Character)
	{
		OnFinished.Broadcast();
		EndTask();
		return;
	}
	// TODO: Implement the actual dash movement (e.g., launch character)

	// Set a timer for the dash duration
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UAlsxtAbilityTaskDash::OnTimerFinished, DashDuration, false);
}

void UAlsxtAbilityTaskDash::OnTimerFinished()
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnFinished.Broadcast();
	}
	EndTask();
}

void UAlsxtAbilityTaskDash::OnDestroy(bool bInOwnerFinished)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	Super::OnDestroy(bInOwnerFinished);
}
