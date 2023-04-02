// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBotController.h"

void APlayerBotController::SetupInputComponent()
{
	Super::SetupInputComponent();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Initing input");

	InputComponent->BindAxis("Horizontal", this, &APlayerBotController::OnHorizontalAxis);
	InputComponent->BindAxis("Vertical", this, &APlayerBotController::OnVerticalAxis);
}

void APlayerBotController::OnHorizontalAxis(float val)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Horizontal: %f"), val));
}

void APlayerBotController::OnVerticalAxis(float val)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Vertical: %f"), val));
}

void APlayerBotController::Tick(float dt)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Ticked"));
}