// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"

#include "AbilitySystemComponent/SkywalkerAbilitySystemComponent.h"

/**
 * 
 */
class SKYWALKERGAMEPLAYABILITYSYSTEM_API SkywalkerCharacterPart_GAS : public IAbilitySystemInterface
{
public:
	SkywalkerCharacterPart_GAS();
	~SkywalkerCharacterPart_GAS();

#pragma region Ability System Component

public:
	// Ability System Component 名称
	static FName AbilitySystemComponentName;

	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS")
	USkywalkerAbilitySystemComponent* AbilitySystemComponent;

	// 获取 Ability System Component
	virtual USkywalkerAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// 给 Ability System Component 添加 Ability
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS")
	void AddAbility(TSubclassOf<UGameplayAbility> AbilityToAdd);

#pragma endregion
};
