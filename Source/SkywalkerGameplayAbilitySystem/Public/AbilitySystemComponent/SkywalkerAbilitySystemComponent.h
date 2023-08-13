// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "Include/SkywalkerGASEnum.h"
#include "Include/SkywalkerGASConfigStructure.h"

#include "GameplayAbility/SkywalkerGameplayAbilityBase.h"
#include "SkillAttribute/SkywalkerSkillAttributeSet.h"
#include "Skill/SkywalkerSkill.h"

#include "SkywalkerAbilitySystemComponent.generated.h"

typedef TMap<int32, USkywalkerSkill*> SkywalkerSkillMap;

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
		FGameplayAbilitySpecHandle AddAbilityByConfig(const FSkywalkerSkillDataTable& SkillDataConfig, const FSkywalkerSkillLevelTable& SkillLevelConfig);
	
	// 移除技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Ability")
		void RemoveAbility(const FGameplayAbilitySpecHandle& AbilityHandle);
	
#pragma region Skywalker Skill
private:
	
	// 拥有的技能列表
	SkywalkerSkillMap HasSkillMap;

public:
	
	// 通过技能配置和等级配置增加技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		void AddSkillByConfig(const FSkywalkerSkillDataTable& SkillDataConfig, const FSkywalkerSkillLevelTable& SkillLevelConfig);

	/**
	* 通过技能等级ID增加技能
	* @param	InSkillLevelID	技能等级ID
	*/
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		void AddSkillByLevelID(int32 InSkillLevelID);

	// 移除技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		void RemoveSkill(int32 SkillID);

	// 通过技能ID获取技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		USkywalkerSkill* GetSkillByID(int32 SkillID) const;

#pragma endregion
	
};
