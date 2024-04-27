// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SkywalkerCharacterPart_GAS.h"

FName  SkywalkerCharacterPart_GAS::AbilitySystemComponentName(TEXT("AbilitySystemComponent"));

SkywalkerCharacterPart_GAS::SkywalkerCharacterPart_GAS()
{
}

SkywalkerCharacterPart_GAS::~SkywalkerCharacterPart_GAS()
{
}

#pragma region Ability System Component

USkywalkerAbilitySystemComponent* SkywalkerCharacterPart_GAS::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void SkywalkerCharacterPart_GAS::AddAbility(TSubclassOf<UGameplayAbility> AbilityToAdd)
{
	if (AbilitySystemComponent == nullptr)
	{
		return;
	}

	if (AbilityToAdd == nullptr)
	{
		return;
	}

	AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToAdd, 1));
}

#pragma endregion
