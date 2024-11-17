// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Element.generated.h"

/**
 * 元素属性集
 * 类似 火伤害，冰伤害这种元素属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Element : public UAttributeSet
{
	GENERATED_BODY()

public:
#pragma region 元素，影响所有元素

	/**
	 * 元素伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Damage_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Damage_Element)

	/**
	 * 元素效果
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Effect_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Effect_Element)

	/**
	 * 元素抗性
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Resistance_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Resistance_Element)

	/**
	 * 元素抗性上限
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData ResistanceMax_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, ResistanceMax_Element)

	/**
	 * 元素穿透
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Penetration_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Penetration_Element)

	/**
	 * 元素暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritRate_Element)

	/**
	 * 元素暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage_Element;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritDamage_Element)

#pragma endregion 影响所有元素

#pragma region 火

	/**
	 * 火伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Damage_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Damage_Fire)

	/**
	 * 火效果
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Effect_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Effect_Fire)

	/**
	 * 火抗性
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Resistance_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Resistance_Fire)

	/**
	 * 火抗性上限
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData ResistanceMax_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, ResistanceMax_Fire)

	/**
	 * 火穿透
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Penetration_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Penetration_Fire)

	/**
	 * 火暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritRate_Fire)

	/**
	 * 火暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage_Fire;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritDamage_Fire)

#pragma endregion 火

#pragma region 冰

	/**
	 * 冰伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Damage_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Damage_Ice)

	/**
	 * 冰效果
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Effect_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Effect_Ice)

	/**
	 * 冰抗性
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Resistance_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Resistance_Ice)

	/**
	 * 冰抗性上限
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData ResistanceMax_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, ResistanceMax_Ice)

	/**
	 * 冰穿透
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Penetration_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Penetration_Ice)

	/**
	 * 冰暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritRate_Ice)

	/**
	 * 冰暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage_Ice;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritDamage_Ice)

#pragma endregion 冰

#pragma region 电

	/**
	 * 电伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Damage_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Damage_Lightning)

	/**
	 * 电效果
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Effect_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Effect_Lightning)

	/**
	 * 电抗性
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Resistance_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Resistance_Lightning)

	/**
	 * 电抗性上限
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData ResistanceMax_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, ResistanceMax_Lightning)

	/**
	 * 电穿透
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Penetration_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, Penetration_Lightning)

	/**
	 * 电暴击率
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritRate_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritRate_Lightning)

	/**
	 * 电暴击伤害
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData CritDamage_Lightning;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Element, CritDamage_Lightning)

#pragma endregion 电
};
