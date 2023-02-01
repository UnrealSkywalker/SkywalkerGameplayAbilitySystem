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

// Skywalker 技能子类型
UENUM(BlueprintType)
enum class ESkywalkerSkillSubType : uint8
{
	Invalid = 0,	// 无效
	Attack,		// 攻击技能
	Defense,	// 防御技能
	Heal,		// 治疗技能
	Control,	// 控制技能
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
	
	// 
};
