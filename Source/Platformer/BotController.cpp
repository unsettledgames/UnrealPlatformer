// Fill out your copyright notice in the Description page of Project Settings.


#include "BotController.h"

// Sets default values
ABotController::ABotController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABotController::BeginPlay()
{
	Super::BeginPlay();
	SetupPlayerInputComponent(InputComponent);
}

// Called every frame
void ABotController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABotController::OnVerticalInput(float val)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Vertical");
}

void ABotController::OnHorizontalInput(float val)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Horizontal");
}

// Called to bind functionality to input
void ABotController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Setup input");

	APlayerController* controller = Cast<APlayerController>(Controller);
	controller->InputComponent->BindAxis("Vertical", this, &ABotController::OnVerticalInput);
	controller->InputComponent->BindAxis("Horizontal", this, &ABotController::OnHorizontalInput);
}

