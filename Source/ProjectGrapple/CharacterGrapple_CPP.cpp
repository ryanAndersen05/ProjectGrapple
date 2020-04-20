// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGrapple_CPP.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterGrapple_CPP::ACharacterGrapple_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	MainPlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainPlayerCamera->AttachToComponent(CameraSpringArm, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, true));
	
	
}

// Called when the game starts or when spawned
void ACharacterGrapple_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterGrapple_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterGrapple_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

