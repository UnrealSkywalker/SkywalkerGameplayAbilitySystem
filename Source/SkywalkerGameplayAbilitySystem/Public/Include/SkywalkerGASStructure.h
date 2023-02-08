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
