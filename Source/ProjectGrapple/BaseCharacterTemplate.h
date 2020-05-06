// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "BaseCharacterTemplate.generated.h"

UCLASS()
class PROJECTGRAPPLE_API ABaseCharacterTemplate : public ACharacter
{
	GENERATED_BODY()


#pragma region variables
public:
#pragma region const variables
	const FName MoveForwardAxis = TEXT("MoveForward");
	const FName MoveRightAxis = TEXT("MoveRight");
	const FName AimVerticalAxis = TEXT("AimVertical");
	const FName AimHorizontalAxis = TEXT("AimHorizontal");
	const FName JumpActionName = TEXT("Jump");
	const FName ShootActionName = TEXT("Shoot");
#pragma endregion const variables

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* MainPlayerCamera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpringArmComponent* CameraSpringArm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AimingSensitivity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CharacterTurnRate;
#pragma endregion variables


#pragma region functions
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void MouseYaw(float MouseX);
	virtual void MousePitch(float MouseY);
	virtual void MoveForward(float MoveY);
	virtual void MoveRight(float MoveX);
	virtual void CharacterJump();
	virtual void CharacterStopJump();

public:	
	// Sets default values for this character's properties
	ABaseCharacterTemplate();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

#pragma endregion functions
