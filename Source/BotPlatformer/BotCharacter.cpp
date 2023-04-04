// Fill out your copyright notice in the Description page of Project Settings.


#include "BotCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Animation/AnimInstance.h"

// Sets default values
ABotCharacter::ABotCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->SetupAttachment(RootComponent);
	CameraArm->bUsePawnControlRotation = true;
	CameraArm->TargetArmLength = 300.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	USkeletalMeshComponent* mesh;
	mesh = FindComponentByClass<USkeletalMeshComponent>();

	// TODO: inherit from UAnimationInstance and use it as the blueprint animation
	if (mesh != nullptr)
		m_Animation = mesh->GetAnimInstance();
}

// Called when the game starts or when spawned
void ABotCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABotCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABotCharacter::OnHorizontalInput(float val)
{
	if (val == 0.0f) return;
	FRotator rot = Controller->GetControlRotation();
	FRotator yaw = { 0.0f, rot.Yaw, 0.0f };

	FVector dir = FRotationMatrix(yaw).GetUnitAxis(EAxis::Y);
	AddMovementInput(dir * val);
}

void ABotCharacter::OnVerticalInput(float val)
{
	if (val == 0.0f) return;
	FRotator rot = Controller->GetControlRotation();
	FRotator yaw = { 0.0f, rot.Yaw, 0.0f };

	FVector dir = FRotationMatrix(yaw).GetUnitAxis(EAxis::X);
	AddMovementInput(dir * val);
}

void ABotCharacter::OnCameraRotate(float val)
{
	if (val != 0)
		AddControllerYawInput(val);
}

void ABotCharacter::OnCameraLookUp(float val)
{
	if (val != 0)
		AddControllerPitchInput(val);
}

// Called to bind functionality to input
void ABotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &ABotCharacter::OnHorizontalInput);
	PlayerInputComponent->BindAxis("Vertical", this, &ABotCharacter::OnVerticalInput);

	PlayerInputComponent->BindAxis("CameraRotation", this, &ABotCharacter::OnCameraRotate);
	PlayerInputComponent->BindAxis("CameraLookUp", this, &ABotCharacter::OnCameraLookUp);

}

