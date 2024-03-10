// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"

#include "Include/SkywalkerGASEnum.h"
#include "Include/SkywalkerGASStructure.h"

#include "SkywalkerGameplayAbilityBase.generated.h"

/**
 *
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	USkywalkerGameplayAbilityBase(const FObjectInitializer& ObjectInitializer);

#pragma region 技能属性

protected:
	// 技能属性集
	FSkywalkerSkillAttributeSet SkillAttributeSet;
public:
	// 设置技能等级属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
	void SetSkillAttributeSet(const FSkywalkerSkillAttributeSet& OtherSkillAttributeSet);

	// 清理技能属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
	void ClearSkillAttributeSet();

	// 获取某个技能属性的值
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
	int32 GetSkillAttributeValue(ESkywalkerSkillAttributeType SkillAttributeType);

#pragma endregion

};
