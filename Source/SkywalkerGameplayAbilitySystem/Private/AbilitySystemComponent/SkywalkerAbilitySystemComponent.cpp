// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent/SkywalkerAbilitySystemComponent.h"

// 增加技能
FGameplayAbilitySpecHandle USkywalkerAbilitySystemComponent::AddAbility(TSubclassOf<USkywalkerGameplayAbilityBase> AddAbilityClass)
{
	if (AddAbilityClass == nullptr)
	{
		return FGameplayAbilitySpecHandle();
	}

	// 创建技能
	USkywalkerGameplayAbilityBase* AddAbility = NewObject<USkywalkerGameplayAbilityBase>(this, AddAbilityClass);

	USkywalkerSkillAttributeSet* SkillAttributeSet = NewObject<USkywalkerSkillAttributeSet>();

	// TODO shyfan 临时测试
	SkillAttributeSet->AddSkillAttribute(ESkywalkerSkillAttributeType::ProjectileCount, 3);
	AddAbility->SetSkillAttributeSet(SkillAttributeSet);
	
	// 返回技能规格句柄
	FGameplayAbilitySpecHandle Handle = GiveAbility(FGameplayAbilitySpec(AddAbility, 1));
	
	return Handle;
}
