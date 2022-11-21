// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

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

#pragma region Ability System Component
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkywalkerGAS")
		UAbilitySystemComponent* AbilitySystemComponent;
public:
	static FName AbilitySystemComponentName;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override ;
	
#pragma endregion
};
