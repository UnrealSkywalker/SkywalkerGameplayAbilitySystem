// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayAbilitySpec.h"

#include "Include/SkywalkerGASConfigStructure.h"

#include "SkywalkerSkill.generated.h"

/**
 * 
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerSkill : public UObject
{
	GENERATED_BODY()

public:
	USkywalkerSkill(const FObjectInitializer& ObjectInitializer);
	
private:
	// 技能数据配置
	UPROPERTY()
		FSkywalkerSkillDataTable SkillDataConfig;
	
	// 技能等级配置
	UPROPERTY()
		FSkywalkerSkillLevelTable SkillLevelConfig;

	// GameplayAbility Handle
	UPROPERTY()
		FGameplayAbilitySpecHandle AbilityHandle;

public:
	// 设置技能数据配置
	void SetSkillDataConfig(const FSkywalkerSkillDataTable& InSkillDataConfig);

	// 设置技能等级配置
	void SetSkillLevelConfig(const FSkywalkerSkillLevelTable& InSkillLevelConfig);

	// 获取技能ID
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		int32 GetSkillID() const;

	// 获取技能等级
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		int32 GetSkillLevel() const;

	// 获取GameplayAbility类
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		TSubclassOf<class USkywalkerGameplayAbilityBase> GetAbilityClass() const;

	// 设置GameplayAbility Handle
	void SetAbilityHandle(const FGameplayAbilitySpecHandle& InAbilityHandle);

	// 获取GameplayAbility Handle
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
		FGameplayAbilitySpecHandle GetAbilityHandle() const;
};
