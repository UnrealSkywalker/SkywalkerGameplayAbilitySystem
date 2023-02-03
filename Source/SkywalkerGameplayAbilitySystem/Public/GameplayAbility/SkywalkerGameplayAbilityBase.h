// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"

#include "SkillAttributeSet/SkywalkerSkillAttributeSet.h"

#include "SkywalkerGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	
	USkywalkerGameplayAbilityBase();

#pragma region 技能属性

protected:

	// 技能ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute", meta = (AllowPrivateAccess = "true"))
		int32 SkillID;
	
	// 技能等级
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute", meta = (AllowPrivateAccess = "true"))
		int32 SkillLevel;

	// 技能等级属性集
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute", meta = (AllowPrivateAccess = "true"))
		USkywalkerSkillAttributeSet* SkillLevelAttributeSet;
	
	// 辅助技能属性集
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute", meta = (AllowPrivateAccess = "true"))
		USkywalkerSkillAttributeSet* AssistSkillAttributeSet;
public:
	// 设置技能等级属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void SetSkillLevelAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet);
	
	// 清理辅助技能属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void ClearAssistSkillAttributeSet();

	// 增加辅助技能属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void AddAssistSkillAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet);
#pragma endregion

};
