// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet/SkywalkerAttributeSetMacro.h"
#include "SkywalkerAttributeSet_Resource.generated.h"

/**
 * 资源属性集
 * 类似 怒气、法力这种资源属性
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSet_Resource : public UAttributeSet
{
	GENERATED_BODY()

public:
#pragma region 怒气，使用技能获得

	/**
	 * 怒气
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Rage;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, Rage)

	/**
	 * 最大怒气
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, MaxRage)

#pragma endregion 怒气，使用技能获得

#pragma region 能量，自动恢复

	/**
	 * 能量
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, Energy)

	/**
	 * 最大能量
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, MaxEnergy)

#pragma endregion 能量，自动恢复

#pragma region 点数，连击获得

	/**
	 * 点数
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Point;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, Point)

	/**
	 * 最大点数
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MaxPoint;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, MaxPoint)

#pragma endregion 点数，连击获得

#pragma region 灵魂，击杀获得

	/**
	 * 灵魂
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Soul;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, Soul)

	/**
	 * 最大灵魂
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData MaxSoul;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSet_Resource, MaxSoul)

#pragma endregion 灵魂，击杀获得
};
