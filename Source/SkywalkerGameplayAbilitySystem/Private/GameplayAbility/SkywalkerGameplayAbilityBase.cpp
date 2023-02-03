// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/SkywalkerGameplayAbilityBase.h"

USkywalkerGameplayAbilityBase::USkywalkerGameplayAbilityBase()
{
	SkillLevelAttributeSet = NewObject<USkywalkerSkillAttributeSet>();
	AssistSkillAttributeSet = NewObject<USkywalkerSkillAttributeSet>();
}

#pragma region 技能属性

// 设置技能等级属性集
void USkywalkerGameplayAbilityBase::SetSkillLevelAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet)
{
	// 拷贝属性集
	this->SkillLevelAttributeSet->CopyFrom(OtherSkillAttributeSet);
}

// 清理辅助技能属性集
void USkywalkerGameplayAbilityBase::ClearAssistSkillAttributeSet()
{
	AssistSkillAttributeSet->ClearSkillAttributeList();
}

// 增加辅助技能属性集
void USkywalkerGameplayAbilityBase::AddAssistSkillAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet)
{
	AssistSkillAttributeSet->AddSkillAttributeSet(OtherSkillAttributeSet);
}

#pragma endregion

