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
	// 无效
	Invalid = 0,
	// 主动技能
	Active,
	// 被动技能
	Passive,
	// 辅助技能
	Assist,
};

// Skywalker 技能标签
UENUM(BlueprintType)
enum class ESkywalkerSkillTag : uint8
{
	// 无效标签
	Invaild = 0,
	// 单体
	SingleTarget = 1,
	// 范围
	RangeTarget,
};


#pragma region 技能属性相关宏

// Skywalker 技能效果类型
UENUM(BlueprintType)
enum class ESkywalkerSkillAttributeType : uint8
{
	// 无效
	Invalid = 0,
	// 投掷物数量
	ProjectileCount,
};

#pragma endregion
