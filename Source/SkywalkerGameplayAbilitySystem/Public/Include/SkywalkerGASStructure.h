/** Skywalker File Head
* 文件名：SkywalkerGASStructure.h
* 作者：shyfan
* 时间：2023-2-2
* 说明：GAS相关的结构体
*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "SkywalkerGASEnum.h"

#include "SkywalkerGASStructure.generated.h"

#pragma region 技能属性结构体

// Skywalker 技能属性结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillAttribute
{
	GENERATED_USTRUCT_BODY()

#pragma region 属性
		
	// 技能效果类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute")
		ESkywalkerSkillAttributeType AttributeType;

	// 技能效果值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute")
		int32 AttributeValue;
	
#pragma endregion

#pragma region 函数

	// 两个属性是否是同一种属性
	bool IsSameAttribute(const FSkywalkerSkillAttribute& OtherAttribute) const
	{
		return AttributeType == OtherAttribute.AttributeType;
	}
	
	bool IsSameAttribute(const ESkywalkerSkillAttributeType OtherAttributeType) const
	{
		return AttributeType == OtherAttributeType;
	}
	
#pragma endregion

};

#pragma endregion

#pragma region 技能配置结构体

// 技能数据结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillDataTable:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
		FSkywalkerSkillDataTable(){}

#pragma region 属性
		
	// 技能ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ID;

	// 技能主类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESkywalkerSkillMainType MainType;

	// 技能标签
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSet<ESkywalkerSkillTag> SkillTags;

#pragma endregion

#pragma region 函数

#pragma endregion

};

// 技能等级结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillLevelTable:public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
		FSkywalkerSkillLevelTable(){}
		
#pragma region 属性

	// ID，规则：技能ID*1000 + 等级
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ID;
	
	// 技能属性列表
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSkywalkerSkillAttribute> SkillAttributes;
#pragma endregion

#pragma region 函数
	// 获得技能ID
	int32 GetSkillID() const
	{
		return ID / 1000;
	}

	// 获得技能等级
	int32 GetSkillLevel() const
	{
		return ID % 1000;
	}
#pragma endregion

};

#pragma endregion
