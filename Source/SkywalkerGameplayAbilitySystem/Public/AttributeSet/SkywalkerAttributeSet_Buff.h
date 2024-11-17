// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Buff.generated.h"

/**
 * 效果属性集
 * 主要是影响效果的属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Buff : public UAttributeSet
{
	GENERATED_BODY()

public:
#pragma region 效果持续时间

	/**
	 * 增益效果持续时间固定值，单位毫秒
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData DurationBuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, DurationBuff_Fixed)

	/**
	 * 增益效果持续时间万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData DurationBuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, DurationBuff_Percent)

	/**
	 * 减益效果持续时间固定值，单位毫秒
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData DurationDebuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, DurationDebuff_Fixed)

	/**
	 * 减益效果持续时间万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData DurationDebuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, DurationDebuff_Percent)

#pragma endregion 效果持续时间

#pragma region 效果强化

	/**
	 * 增益效果强化固定值
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData AmplifyBuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, AmplifyBuff_Fixed)

	/**
	 * 增益效果强化万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData AmplifyBuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, AmplifyBuff_Percent)

	/**
	 * 减益效果强化固定值
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData AmplifyDebuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, AmplifyDebuff_Fixed)

	/**
	 * 减益效果强化万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData AmplifyDebuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, AmplifyDebuff_Percent)

#pragma endregion 效果强化

#pragma region 效果间隔

	/**
	 * 增益效果间隔固定值，单位毫秒
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData IntervalBuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, IntervalBuff_Fixed)

	/**
	 * 增益效果间隔万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData IntervalBuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, IntervalBuff_Percent)

	/**
	 * 减益效果间隔固定值，单位毫秒
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData IntervalDebuff_Fixed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, IntervalDebuff_Fixed)

	/**
	 * 减益效果间隔万分比
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData IntervalDebuff_Percent;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Buff, IntervalDebuff_Percent)

#pragma endregion 效果间隔
};
