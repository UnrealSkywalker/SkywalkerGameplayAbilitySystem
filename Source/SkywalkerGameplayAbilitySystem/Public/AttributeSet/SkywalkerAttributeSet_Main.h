// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Main.generated.h"

/**
 * 主要属性集
 * 类似 力量、敏捷、智力这种主要属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Main : public UAttributeSet
{
	GENERATED_BODY()

public:
	/**
	 * 力量
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Main, Strength)

	/**
	 * 敏捷
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Main, Agility)

	/**
	 * 智力
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Main, Intelligence)
};
