/** Skywalker File Head
* 文件名：SkywalkerGASEnum.h
* 作者：shyfan
* 时间：2023-1-10
* 说明：GAS相关的枚举
*/

#pragma once

#include "CoreMinimal.h"

// Skywalker 技能主类型
UENUM(BlueprintType)
enum class ESkywalkerSkillMainType : uint8
{
	Invalid = 0,	// 无效
	Active,		// 主动技能
	Passive,	// 被动技能
	Assist,		// 辅助技能
};

// Skywalker 技能标签
UENUM(BlueprintType)
enum class ESkywalkerSkillTag : uint8
{
	Invaild = 0,	// 无效标签
	// 单体
	SingleTarget = 1,
	// 范围
	RangeTarget,
	
	// 元素类型
};


#pragma region 技能属性相关宏

// Skywalker 技能效果类型
UENUM(BlueprintType)
enum class ESkywalkerSkillAttributeType : uint8
{
	Invalid = 0,	// 无效
};

#pragma endregion
