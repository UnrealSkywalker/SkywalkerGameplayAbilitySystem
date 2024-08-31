// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/SkywalkerSkill.h"

USkywalkerSkill::USkywalkerSkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

// 设置技能数据配置
void USkywalkerSkill::SetSkillDataConfig(const FSkywalkerSkillDataTable& InSkillDataConfig)
{
	SkillID = InSkillDataConfig.ID;
}

// 设置技能等级配置
void USkywalkerSkill::SetSkillLevelConfig(const FSkywalkerSkillLevelTable& InSkillLevelConfig)
{
	SkillID = InSkillLevelConfig.GetSkillID();
	SkillLevel = InSkillLevelConfig.GetSkillLevel();
}

// 获取技能ID
int32 USkywalkerSkill::GetSkillID() const
{
	return SkillID;
}

// 获取技能等级
int32 USkywalkerSkill::GetSkillLevel() const
{
	return SkillLevel;
}

// 设置GameplayAbility Handle
void USkywalkerSkill::SetAbilityHandle(FGameplayAbilitySpecHandle InAbilityHandle)
{
	AbilityHandle = InAbilityHandle;
}

// 获取GameplayAbility Handle
FGameplayAbilitySpecHandle USkywalkerSkill::GetAbilityHandle() const
{
	return AbilityHandle;
}
