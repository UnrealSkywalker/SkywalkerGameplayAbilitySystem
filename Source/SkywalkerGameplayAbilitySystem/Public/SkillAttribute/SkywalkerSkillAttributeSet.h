// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Include/SkywalkerGASEnum.h"
#include "Include/SkywalkerGASStructure.h"

#include "SkywalkerSkillAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerSkillAttributeSet : public UObject
{
	GENERATED_BODY()
	
private:
	// 技能属性列表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute", meta = (AllowPrivateAccess = "true"))
		TArray<FSkywalkerSkillAttribute> SkillAttributeList;
	
public:
	USkywalkerSkillAttributeSet();

	// 增加技能属性，如果属性已存在则累加值
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void AddSkillAttribute(ESkywalkerSkillAttributeType AttributeType, int32 AttributeValue);

	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void AddSkillAttributeStruct(const FSkywalkerSkillAttribute& SkillAttribute);

	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void AddSkillAttributeSet(USkywalkerSkillAttributeSet* OtherSkillAttributeSet);

	// 移除技能属性
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void RemoveSkillAttribute(ESkywalkerSkillAttributeType AttributeType);

	// 获取技能属性列表
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		TArray<FSkywalkerSkillAttribute> GetSkillAttributeList();

	// 清理技能属性列表
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void ClearSkillAttributeList();

	// 拷贝其他的技能属性集
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		void CopyFrom(USkywalkerSkillAttributeSet* OtherSkillAttributeSet);

	// 是否有某个属性
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		bool HasSkillAttribute(ESkywalkerSkillAttributeType AttributeType);

	// 后的某个属性值
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SkillAttribute")
		int32 GetSkillAttributeValue(ESkywalkerSkillAttributeType AttributeType);
};
