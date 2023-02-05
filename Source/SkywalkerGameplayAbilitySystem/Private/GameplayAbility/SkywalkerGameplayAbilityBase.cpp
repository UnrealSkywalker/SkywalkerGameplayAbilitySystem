// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/SkywalkerGameplayAbilityBase.h"

USkywalkerGameplayAbilityBase::USkywalkerGameplayAbilityBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::NonInstanced;

	SkillAttributeSet = NewObject<USkywalkerSkillAttributeSet>();
}

#pragma region 技能属性

// 设置技能等级属性集
void USkywalkerGameplayAbilityBase::SetSkillAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet)
{
	// 拷贝属性集
	SkillAttributeSet->CopyFrom(OtherSkillAttributeSet);
}

// 清理技能属性集
void USkywalkerGameplayAbilityBase::ClearSkillAttributeSet()
{
	SkillAttributeSet->ClearSkillAttributeList();
}

// 获取某个技能属性的值
int32 USkywalkerGameplayAbilityBase::GetSkillAttributeValue(ESkywalkerSkillAttributeType SkillAttributeType)
{
	return SkillAttributeSet->GetSkillAttributeValue(SkillAttributeType);
}

#pragma endregion

