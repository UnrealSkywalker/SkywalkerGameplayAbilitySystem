// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

#include "SkywalkerAttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	   GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	   GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	   GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	   GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API USkywalkerAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
public:
	USkywalkerAttributeSetBase();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

#pragma region 生命值

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSetBase, Health);

	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS", ReplicatedUsing = OnRep_MaxHealth)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USkywalkerAttributeSetBase, MaxHealth);

	UFUNCTION()
		virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

#pragma endregion
};
