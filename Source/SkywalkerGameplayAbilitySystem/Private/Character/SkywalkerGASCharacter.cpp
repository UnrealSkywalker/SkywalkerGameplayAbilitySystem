// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SkywalkerGASCharacter.h"

FName  ASkywalkerGASCharacter::AbilitySystemComponentName(TEXT("AbilitySystemComponent"));

// Sets default values
ASkywalkerGASCharacter::ASkywalkerGASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(ASkywalkerGASCharacter::AbilitySystemComponentName);
}

// Called when the game starts or when spawned
void ASkywalkerGASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkywalkerGASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkywalkerGASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

#pragma region Ability System Component

UAbilitySystemComponent* ASkywalkerGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

#pragma endregion
