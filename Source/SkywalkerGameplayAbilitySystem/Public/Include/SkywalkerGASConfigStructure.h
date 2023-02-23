/** Skywalker File Head
* 文件名：SkywalkerGASConfigStructure.h
* 作者：shyfan
* 时间：2023-2-7
* 说明：GAS配置结构体
*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "SkywalkerGASEnum.h"
#include "SkywalkerGASStructure.h"

#include "SkywalkerGASConfigStructure.generated.h"

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

	// GameplayAbility类
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class USkywalkerGameplayAbilityBase> GameplayAbilityClass;

#pragma endregion

#pragma region 函数

	// 获取技能ID
	int32 GetSkillID() const
	{
		return ID;
	}

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
