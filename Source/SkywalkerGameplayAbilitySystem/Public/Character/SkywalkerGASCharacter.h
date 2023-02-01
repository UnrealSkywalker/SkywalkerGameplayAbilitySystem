// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

#include "AbilitySystemComponent/SkywalkerAbilitySystemComponent.h"
#include "AttributeSet/SkywalkerAttributeSetBase.h"

#include "SkywalkerGASCharacter.generated.h"

UCLASS()
class SKYWALKERGAMEPLAYABILITYSYSTEM_API ASkywalkerGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkywalkerGASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region AttributeSet
	
private:
	
	void InitAttributeSet();
	
public:

	// 基础属性
	static FName BaseAttributeName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS|AttributeSet")
		USkywalkerAttributeSetBase* AttributeSetBase;
	
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS|AttributeSet")
		USkywalkerAttributeSetBase* GetAttributeSetBase() const;

#pragma endregion

#pragma region Ability System Component
	
public:
	// Ability System Component 名称
	static FName AbilitySystemComponentName;

	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS")
		USkywalkerAbilitySystemComponent* AbilitySystemComponent;
	
	// 获取 Ability System Component
	virtual USkywalkerAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// 给 Ability System Component 添加 Ability
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS")
		void AddAbility(TSubclassOf<UGameplayAbility> AbilityToAdd);

	// 给 Ability System Component 添加 Ability
	UFUNCTION(BlueprintCallable, Category = "SkywalkerGAS")
		void AddAbilityByObject(UGameplayAbility* AbilityToAdd);
	
#pragma endregion
};
