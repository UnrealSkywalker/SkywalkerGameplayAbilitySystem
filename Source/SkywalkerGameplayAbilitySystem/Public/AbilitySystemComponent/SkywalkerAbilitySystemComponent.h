// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "GameplayAbility/SkywalkerGameplayAbilityBase.h"
#include "SkillAttributeSet/SkywalkerSkillAttributeSet.h"
#include "Include/SkywalkerGASEnum.h"

#include "SkywalkerAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	// 增加技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Ability")
		FGameplayAbilitySpecHandle AddAbility(TSubclassOf<USkywalkerGameplayAbilityBase> AddAbilityClass);
};
