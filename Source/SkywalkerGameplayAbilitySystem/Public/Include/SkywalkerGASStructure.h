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

#pragma region 技能效果结构体

// Skywalker 技能效果结构体
USTRUCT(BlueprintType)
struct FSkywalkerSkillEffect
{
	GENERATED_USTRUCT_BODY()

		// 技能效果类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillEffect")
		ESkywalkerSkillEffectType SkillEffectType;

	// 技能效果值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skywalker|SkillEffect")
		int32 SkillEffectValue;
};

#pragma endregion
