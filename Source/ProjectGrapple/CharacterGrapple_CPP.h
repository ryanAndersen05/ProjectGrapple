// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterGrapple_CPP.generated.h"

UCLASS()
class PROJECTGRAPPLE_API ACharacterGrapple_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterGrapple_CPP();

protected:
#pragma region Default Methods
	virtual void BeginPlay() override;
#pragma endregion Default Methods

public:	
#pragma region Default Methods
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* MainPlayerCamera;
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* CameraSpringArm;
#pragma endregion

	

};
