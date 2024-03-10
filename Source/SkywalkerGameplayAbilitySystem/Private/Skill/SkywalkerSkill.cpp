// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/SkywalkerSkill.h"

USkywalkerSkill::USkywalkerSkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

// 设置技能数据配置
void USkywalkerSkill::SetSkillDataConfig(const FSkywalkerSkillDataTable& InSkillDataConfig)
{
	SkillDataConfig = InSkillDataConfig;
}

// 设置技能等级配置
void USkywalkerSkill::SetSkillLevelConfig(const FSkywalkerSkillLevelTable& InSkillLevelConfig)
{
	SkillLevelConfig = InSkillLevelConfig;
}

// 获取技能ID
int32 USkywalkerSkill::GetSkillID() const
{
	return SkillDataConfig.GetSkillID();
}

// 获取技能等级
int32 USkywalkerSkill::GetSkillLevel() const
{
	return SkillLevelConfig.GetSkillLevel();
}

// 获取GameplayAbility类
TSubclassOf<class USkywalkerGameplayAbilityBase> USkywalkerSkill::GetAbilityClass() const
{
	return SkillDataConfig.GameplayAbilityClass;
}

// 设置GameplayAbility Handle
void USkywalkerSkill::SetAbilityHandle(const FGameplayAbilitySpecHandle& InAbilityHandle)
{
	AbilityHandle = InAbilityHandle;
}

// 获取GameplayAbility Handle
FGameplayAbilitySpecHandle USkywalkerSkill::GetAbilityHandle() const
{
	return AbilityHandle;
}
