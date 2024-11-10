// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Basic.generated.h"

/**
 * 基础属性集
 * 类似 生命值、最大生命值、移动速度这种基础属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Basic : public UAttributeSet
{
	GENERATED_BODY()

public:
	/**
	 * 生命值
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Basic, Health)

	/**
	 * 最大生命值
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Basic, MaxHealth)

	/**
	 * 移动速度
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Basic, MoveSpeed)

	/**
	 * 命中
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Hit;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Basic, Hit)

	/**
	 * 闪避
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Dodge;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Basic, Dodge)
};
