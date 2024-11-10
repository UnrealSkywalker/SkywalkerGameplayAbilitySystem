// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/SkywalkerAbilitySystemComponent.h"

#pragma region Skywalker Skill

// 增加技能
FGameplayAbilitySpecHandle USkywalkerAbilitySystemComponent::AddAbilityByConfig(const FSkywalkerSkillDataTable &SkillDataConfig, const FSkywalkerSkillLevelTable &SkillLevelConfig)
{
	if (SkillLevelConfig.GetSkillID() != SkillDataConfig.GetSkillID())
	{
		return FGameplayAbilitySpecHandle();
	}

	// 创建技能
	USkywalkerGameplayAbilityBase *AddAbility = NewObject<USkywalkerGameplayAbilityBase>(this, SkillDataConfig.GameplayAbilityClass);

	FSkywalkerSkillAttributeSet SkillAttributeSet;

	// 遍历技能等级配置的技能属性，添加到技能属性集中
	for (int i = 0; i < SkillLevelConfig.SkillAttributes.Num(); i++)
	{
		SkillAttributeSet.AddSkillAttributeStruct(SkillLevelConfig.SkillAttributes[i]);
	}

	AddAbility->SetSkillAttributeSet(SkillAttributeSet);

	// 返回技能规格句柄
	FGameplayAbilitySpecHandle Handle = GiveAbility(FGameplayAbilitySpec(AddAbility, SkillLevelConfig.GetSkillLevel()));

	return Handle;
}

// 移除技能
void USkywalkerAbilitySystemComponent::RemoveAbility(const FGameplayAbilitySpecHandle &AbilityHandle)
{
	// 移除技能
	ClearAbility(AbilityHandle);
}

void USkywalkerAbilitySystemComponent::AddSkillByLevelID(int32 InSkillLevelID)
{
	UDataTable *SkillLevelTable = nullptr;
	SkillLevelTable = LoadObject<UDataTable>(nullptr, TEXT("/Script/Engine.DataTable'/SkywalkerGameplayAbilitySystem/Config/Data/Skywalker_DT_SkillLevel.Skywalker_DT_SkillLevel'"));
	if (SkillLevelTable)
	{
		SkillLevelTable->AddToRoot();
	}

	FName NameSkillLevelID = FName(*FString::FromInt(InSkillLevelID));
	FSkywalkerSkillLevelTable *SkillLevelConfigs;
	SkillLevelConfigs = SkillLevelTable->FindRow<FSkywalkerSkillLevelTable>(NameSkillLevelID, TEXT("SkillLevelID"));
	if (SkillLevelConfigs == nullptr)
	{
		return;
	}

	UDataTable *SkillDataTable = nullptr;
	SkillDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Script/Engine.DataTable'/SkywalkerGameplayAbilitySystem/Config/Data/Skywalker_DT_SkillData.Skywalker_DT_SkillData'"));
	if (SkillDataTable)
	{
		SkillDataTable->AddToRoot();
	}

	FName NameSkillID = FName(*FString::FromInt(SkillLevelConfigs->GetSkillID()));

	FSkywalkerSkillDataTable *SkillDataConfigs;
	SkillDataConfigs = SkillDataTable->FindRow<FSkywalkerSkillDataTable>(NameSkillID, TEXT("SkillID"));
	if (SkillDataConfigs == nullptr)
	{
		return;
	}

	AddSkillByConfig(*SkillDataConfigs, *SkillLevelConfigs);
}

// 移除技能
void USkywalkerAbilitySystemComponent::RemoveSkill(int32 SkillID)
{
	USkywalkerSkill *Skill = HasSkillMap.FindRef(SkillID);
	if (Skill == nullptr)
	{
		return;
	}

	RemoveAbility(Skill->GetAbilityHandle());

	HasSkillMap.Remove(SkillID);
}

// 通过技能ID获取技能
USkywalkerSkill *USkywalkerAbilitySystemComponent::GetSkillByID(int32 SkillID) const
{
	return HasSkillMap.FindRef(SkillID);
}

bool USkywalkerAbilitySystemComponent::ActivateSkillByID(int32 SkillID)
{
	USkywalkerSkill *Skill = HasSkillMap.FindRef(SkillID);
	if (Skill == nullptr)
	{
		return false;
	}

	// 激活技能
	return TryActivateAbility(Skill->GetAbilityHandle());
}

void USkywalkerAbilitySystemComponent::AddSkillByConfig(const FSkywalkerSkillDataTable &SkillDataConfig, const FSkywalkerSkillLevelTable &SkillLevelConfig)
{
	if (SkillLevelConfig.GetSkillID() != SkillDataConfig.GetSkillID())
	{
		return;
	}

	// 先找到技能
	USkywalkerSkill *Skill = HasSkillMap.FindRef(SkillDataConfig.GetSkillID());
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

#pragma endregion Skywalker Skill

#pragma region Skywalker Attribute

void USkywalkerAbilitySystemComponent::InitAttributeSet()
{
	for (int i = 0; i < AttributeSetClasses.Num(); i++)
	{
		// TODO Shyfan 需要判断是否已经存在
		GetOrCreateAttributeSubobject(AttributeSetClasses[i]);
	}
}

#pragma endregion Skywalker Attribute
