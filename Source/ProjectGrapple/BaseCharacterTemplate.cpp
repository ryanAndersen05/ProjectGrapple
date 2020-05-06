// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacterTemplate.h"

// Sets default values
ABaseCharacterTemplate::ABaseCharacterTemplate()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	MainPlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	CameraSpringArm->bUsePawnControlRotation = true;
	const FAttachmentTransformRules attachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->TargetArmLength = 350;
	MainPlayerCamera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);

	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationPitch = false;

	AimingSensitivity = 1;
	CharacterTurnRate = 10;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

void ABaseCharacterTemplate::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacterTemplate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacterTemplate::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(MoveForwardAxis, this, &ABaseCharacterTemplate::MoveForward);
	PlayerInputComponent->BindAxis(MoveRightAxis, this, &ABaseCharacterTemplate::MoveRight);
	PlayerInputComponent->BindAxis(AimHorizontalAxis, this, &ABaseCharacterTemplate::MouseYaw);
	PlayerInputComponent->BindAxis(AimVerticalAxis, this, &ABaseCharacterTemplate::MousePitch);


	PlayerInputComponent->BindAction(JumpActionName, IE_Pressed, this, &ABaseCharacterTemplate::CharacterJump);
	PlayerInputComponent->BindAction(JumpActionName, IE_Released, this, &ABaseCharacterTemplate::CharacterStopJump);
}

// Aim Left and Right
void ABaseCharacterTemplate::MouseYaw(float MouseX)
{
	AddControllerYawInput(MouseX * AimingSensitivity);
}

// Aim Up and Down
void ABaseCharacterTemplate::MousePitch(float MouseY)
{
	AddControllerPitchInput(-MouseY * AimingSensitivity);
}

// Move forward and back
void ABaseCharacterTemplate::MoveForward(float MoveY)
{
	FVector AdjustedForwardVector = MainPlayerCamera->GetForwardVector();
	AdjustedForwardVector.Z = 0;
	AdjustedForwardVector.Normalize();
	AddMovementInput(AdjustedForwardVector * MoveY);
}

// Move right and back
void ABaseCharacterTemplate::MoveRight(float MoveX)
{
	FVector AdjustedRightVector = MainPlayerCamera->GetRightVector();
	AdjustedRightVector.Z = 0;
	AdjustedRightVector.Normalize();
	AddMovementInput(AdjustedRightVector * MoveX);
}

//Begins the jump process
void ABaseCharacterTemplate::CharacterJump()
{
	Jump();
}

//Ends the jump process
void ABaseCharacterTemplate::CharacterStopJump()
{
	StopJumping();
}

////Turns the character in the direction of the camera if they are moving 
//void ABaseCharacterTemplate::AdjustCharacterRotationWhenMoving(float DeltaTime)
//{
//	if (GetVelocity().Size() <= 0)
//	{
//		return;
//	}
//
//	FRotator MainCameraRotation = MainPlayerCamera->GetComponentRotation();
//	FRotator UpdatedWorldRotation = UKismetMathLibrary::RLerp(GetActorRotation(),
//		FRotator(0, MainCameraRotation.Yaw, 0), DeltaTime * CharacterTurnRate, true);
//
//	SetActorRotation(UpdatedWorldRotation, ETeleportType::None);
//
//}