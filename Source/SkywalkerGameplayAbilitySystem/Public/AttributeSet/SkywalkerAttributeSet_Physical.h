// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Physical.generated.h"

/**
 * 物理属性集
 * 类似 物理伤害，护甲这种物理属性
 * 屬性加上 _Physical 是为了方便拷贝到其他属性集
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Physical : public UAttributeSet
{
	GENERATED_BODY()

public:
	/**
	 * 物理伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Damage_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, Damage_Physical)

	/**
	 * 护甲
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Armor_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, Armor_Physical)

	/**
	 * 格挡率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData BlockRate_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, BlockRate_Physical)

	/**
	 * 格挡效果
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData BlockEffect_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, BlockEffect_Physical)

	/**
	 * 物理暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, CritRate_Physical)

	/**
	 * 物理暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage_Physical;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Physical, CritDamage_Physical)
};
