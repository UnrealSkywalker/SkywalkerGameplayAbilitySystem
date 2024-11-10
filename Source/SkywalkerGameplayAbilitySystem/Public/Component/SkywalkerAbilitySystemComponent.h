// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "Include/SkywalkerGASEnum.h"
#include "Include/SkywalkerGASConfigStructure.h"

#include "GameplayAbility/SkywalkerGameplayAbilityBase.h"
#include "Skill/SkywalkerSkill.h"

#include "SkywalkerAbilitySystemComponent.generated.h"

typedef TMap<int32, USkywalkerSkill *> SkywalkerSkillMap;

/**
 *
 */
UCLASS(ClassGroup = Skywalker, hidecategories = (Object, LOD, Lighting, Transform, Sockets, TextureStreaming), editinlinenew, meta = (BlueprintSpawnableComponent))
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

#pragma region Skill

public:
	// 增加技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Ability")
	FGameplayAbilitySpecHandle AddAbilityByConfig(const FSkywalkerSkillDataTable &SkillDataConfig, const FSkywalkerSkillLevelTable &SkillLevelConfig);

	// 移除技能
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Ability")
	void RemoveAbility(const FGameplayAbilitySpecHandle &AbilityHandle);

private:
	// 拥有的技能列表
	SkywalkerSkillMap HasSkillMap;

public:
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
	USkywalkerSkill *GetSkillByID(int32 SkillID) const;

	/**
	 * 通过技能ID释放技能
	 */
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Skill")
	bool ActivateSkillByID(int32 SkillID);

private:
	/**
	 * 通过技能配置增加技能
	 */
	void AddSkillByConfig(const FSkywalkerSkillDataTable &SkillDataConfig, const FSkywalkerSkillLevelTable &SkillLevelConfig);

#pragma endregion Skill

#pragma region Attribute

public:
	/**
	 * 属性集类
	 * 可在蓝图中增加和删除
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetClass")
	TArray<TSubclassOf<UAttributeSet>> AttributeSetClasses;

	/**
	 * 初始化属性集
	 * 可在蓝图中调用
	 */
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|Attribute")
	void InitAttributeSet();

#pragma endregion Attribute
};
