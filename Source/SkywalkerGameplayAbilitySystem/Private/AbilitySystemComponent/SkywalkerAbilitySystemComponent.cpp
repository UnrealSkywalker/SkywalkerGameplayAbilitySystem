// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent/SkywalkerAbilitySystemComponent.h"

// 增加技能
FGameplayAbilitySpecHandle USkywalkerAbilitySystemComponent::AddAbilityByConfig(const FSkywalkerSkillDataTable& SkillDataConfig, const FSkywalkerSkillLevelTable& SkillLevelConfig)
{
	if (SkillLevelConfig.GetSkillID() != SkillDataConfig.GetSkillID())
	{
		return FGameplayAbilitySpecHandle();
	}

	// 创建技能
	USkywalkerGameplayAbilityBase* AddAbility = NewObject<USkywalkerGameplayAbilityBase>(this, SkillDataConfig.GameplayAbilityClass);

	USkywalkerSkillAttributeSet* SkillAttributeSet = NewObject<USkywalkerSkillAttributeSet>();

	// 遍历技能等级配置的技能属性，添加到技能属性集中
	for (int i = 0; i < SkillLevelConfig.SkillAttributes.Num(); i++)
	{
		SkillAttributeSet->AddSkillAttributeStruct(SkillLevelConfig.SkillAttributes[i]);
	}
	
	AddAbility->SetSkillAttributeSet(SkillAttributeSet);

	// 返回技能规格句柄
	FGameplayAbilitySpecHandle Handle = GiveAbility(FGameplayAbilitySpec(AddAbility, SkillLevelConfig.GetSkillLevel()));

	return Handle;
}

// 移除技能
void USkywalkerAbilitySystemComponent::RemoveAbility(const FGameplayAbilitySpecHandle& AbilityHandle)
{
	// 移除技能
	ClearAbility(AbilityHandle);
}

#pragma region Skywalker Skill

// 通过技能配置和等级配置增加技能
void USkywalkerAbilitySystemComponent::AddSkillByConfig(const FSkywalkerSkillDataTable& SkillDataConfig, const FSkywalkerSkillLevelTable& SkillLevelConfig)
{
	if (SkillLevelConfig.GetSkillID() != SkillDataConfig.GetSkillID())
	{
		return;
	}

	// 先找到技能
	USkywalkerSkill* Skill = HasSkillMap.FindRef(SkillDataConfig.GetSkillID());
	if (Skill == nullptr)
	{
		// 创建技能
		Skill = NewObject<USkywalkerSkill>();
		Skill->SetSkillDataConfig(SkillDataConfig);
		Skill->SetSkillLevelConfig(SkillLevelConfig);
		HasSkillMap.Add(SkillDataConfig.GetSkillID(), Skill);

		Skill->SetAbilityHandle(AddAbilityByConfig(SkillDataConfig, SkillLevelConfig));
	}
	else
	{
		// 更新技能等级
		Skill->SetSkillLevelConfig(SkillLevelConfig);
	}
}

void USkywalkerAbilitySystemComponent::AddSkillByLevelID(int32 InSkillLevelID)
{
	UDataTable* SkillLevelTable = nullptr;
	SkillLevelTable = LoadObject<UDataTable>(nullptr, TEXT("/Script/Engine.DataTable'/SkywalkerGameplayAbilitySystem/Config/Data/Skywalker_DT_SkillLevel.Skywalker_DT_SkillLevel'"));
	if (SkillLevelTable)
	{
		SkillLevelTable->AddToRoot();
	}
	
	FSkywalkerSkillLevelTable* SkillLevelConfigs;
	SkillLevelConfigs = SkillLevelTable->FindRow<FSkywalkerSkillLevelTable>(TEXT("1001001"), TEXT("1001001"));
	if (SkillLevelConfigs ==nullptr)
	{
		return;
	}
	
	UDataTable* SkillDataTable = nullptr;
	SkillDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Script/Engine.DataTable'/SkywalkerGameplayAbilitySystem/Config/Data/Skywalker_DT_SkillData.Skywalker_DT_SkillData'"));
	if (SkillDataTable)
	{
		SkillDataTable->AddToRoot();
	}
	
	FSkywalkerSkillDataTable* SkillDataConfigs;
	SkillDataConfigs = SkillDataTable->FindRow<FSkywalkerSkillDataTable>(TEXT("1001"), TEXT("1001"));
	if (SkillDataConfigs == nullptr)
	{
		return;
	}
	
	AddSkillByConfig(*SkillDataConfigs, *SkillLevelConfigs);
}

// 移除技能
void USkywalkerAbilitySystemComponent::RemoveSkill(int32 SkillID)
{
	USkywalkerSkill* Skill = HasSkillMap.FindRef(SkillID);
	if (Skill == nullptr)
	{
		return;
	}

	RemoveAbility(Skill->GetAbilityHandle());

	HasSkillMap.Remove(SkillID);
}

// 通过技能ID获取技能
USkywalkerSkill* USkywalkerAbilitySystemComponent::GetSkillByID(int32 SkillID) const
{
	return HasSkillMap.FindRef(SkillID);
}

#pragma endregion
