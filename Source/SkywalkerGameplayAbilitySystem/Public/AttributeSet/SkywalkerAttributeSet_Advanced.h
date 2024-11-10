// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Advanced.generated.h"

/**
 * 进阶属性集
 * 类似 攻击速度、施法速度这种进阶属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Advanced : public UAttributeSet
{
	GENERATED_BODY()

public:
	/**
	 * 攻击速度
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Advanced, AttackSpeed)

	/**
	 * 施法速度
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CastSpeed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Advanced, CastSpeed)

	/**
	 * 暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Advanced, CritRate)

	/**
	 * 暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Advanced, CritDamage)
};
