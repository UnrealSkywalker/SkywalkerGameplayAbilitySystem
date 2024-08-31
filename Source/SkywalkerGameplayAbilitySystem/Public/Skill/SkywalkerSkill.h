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
	// GameplayAbility Handle
	UPROPERTY()
	FGameplayAbilitySpecHandle AbilityHandle;

	// 技能ID
	UPROPERTY()
	int32 SkillID = 0;

	// 技能等级
	UPROPERTY()
	int32 SkillLevel = 0;

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

	// 设置GameplayAbility Handle
	void SetAbilityHandle(FGameplayAbilitySpecHandle InAbilityHandle);

	// 获取GameplayAbility Handle
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
	FGameplayAbilitySpecHandle GetAbilityHandle() const;
};
