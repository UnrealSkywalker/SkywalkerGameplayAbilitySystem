/** Skywalker File Head
* 文件名：SkywalkerGASStructure.h
* 作者：shyfan
* 时间：2023-2-2
* 说明：GAS相关的结构体
*/

#pragma once

#include "CoreMinimal.h"

#include "SkywalkerGASEnum.h"

#include "SkywalkerGASStructure.generated.h"

// 技能属性结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillAttribute
{
	GENERATED_USTRUCT_BODY()

#pragma region 属性

	// 技能效果类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute")
	ESkywalkerSkillAttributeType AttributeType{ ESkywalkerSkillAttributeType::Invalid };

	// 技能效果值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute")
	int32 AttributeValue{};

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

// 技能属性集结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillAttributeSet
{
	GENERATED_USTRUCT_BODY()

#pragma region 属性

	// 技能属性列表
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillAttribute")
	TArray<FSkywalkerSkillAttribute> SkillAttributeList;

#pragma endregion

	#pragma region 函数

	// 增加技能属性，如果属性已存在则累加值
	void AddSkillAttribute(ESkywalkerSkillAttributeType AttributeType, int32 AttributeValue)
	{
		for (int32 i = 0; i < SkillAttributeList.Num(); i++)
		{
			if (SkillAttributeList[i].IsSameAttribute(AttributeType))
			{
				SkillAttributeList[i].AttributeValue += AttributeValue;
				return;
			}
		}

		FSkywalkerSkillAttribute SkillAttribute;
		SkillAttribute.AttributeType = AttributeType;
		SkillAttribute.AttributeValue = AttributeValue;
		SkillAttributeList.Add(SkillAttribute);
	}

	void AddSkillAttributeStruct(const FSkywalkerSkillAttribute& SkillAttribute)
	{
		AddSkillAttribute(SkillAttribute.AttributeType, SkillAttribute.AttributeValue);
	}

	void AddSkillAttributeSet(const FSkywalkerSkillAttributeSet& OtherSkillAttributeSet)
	{
		for (int32 i = 0; i < OtherSkillAttributeSet.SkillAttributeList.Num(); i++)
		{
			AddSkillAttributeStruct(OtherSkillAttributeSet.SkillAttributeList[i]);
		}
	}

	// 移除技能属性
	void RemoveSkillAttribute(ESkywalkerSkillAttributeType AttributeType)
	{
		for (int32 i = 0; i < SkillAttributeList.Num(); i++)
		{
			if (SkillAttributeList[i].IsSameAttribute(AttributeType))
			{
				SkillAttributeList.RemoveAt(i);
				return;
			}
		}
	}

	// 获取技能属性列表
	TArray<FSkywalkerSkillAttribute> GetSkillAttributeList() const
	{
		return SkillAttributeList;
	}

	// 清理技能属性列表
	void ClearSkillAttributeList()
	{
		SkillAttributeList.Empty();
	}

	// 拷贝其他的技能属性集
	void CopyFrom(const FSkywalkerSkillAttributeSet& OtherSkillAttributeSet)
	{
		ClearSkillAttributeList();
		AddSkillAttributeSet(OtherSkillAttributeSet);
	}

	// 是否有某个属性
	bool HasSkillAttribute(ESkywalkerSkillAttributeType AttributeType) const
	{
		for (int32 i = 0; i < SkillAttributeList.Num(); i++)
		{
			if (SkillAttributeList[i].IsSameAttribute(AttributeType))
			{
				return true;
			}
		}

		return false;
	}

	// 获取某个属性值
	int32 GetSkillAttributeValue(ESkywalkerSkillAttributeType AttributeType) const
	{
		for (int32 i = 0; i < SkillAttributeList.Num(); i++)
		{
			if (SkillAttributeList[i].IsSameAttribute(AttributeType))
			{
				return SkillAttributeList[i].AttributeValue;
			}
		}

		return 0;
	}
};
