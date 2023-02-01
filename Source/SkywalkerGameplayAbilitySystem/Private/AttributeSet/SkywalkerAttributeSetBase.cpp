// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet/SkywalkerAttributeSetBase.h"

void USkywalkerAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USkywalkerAttributeSetBase, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USkywalkerAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);
}

void USkywalkerAttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USkywalkerAttributeSetBase, Health, OldHealth);
}

void USkywalkerAttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USkywalkerAttributeSetBase, MaxHealth, OldMaxHealth);
}
