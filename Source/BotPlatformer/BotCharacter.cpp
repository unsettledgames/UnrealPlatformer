// Fill out your copyright notice in the Description page of Project Settings.


#include "BotCharacter.h"

// Sets default values
ABotCharacter::ABotCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Horizontal Val: %f"), val));
}

void ABotCharacter::OnVerticalInput(float val)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Vertical Val: %f"), val));

}

// Called to bind functionality to input
void ABotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &ABotCharacter::OnHorizontalInput);
	PlayerInputComponent->BindAxis("Vertical", this, &ABotCharacter::OnVerticalInput);

}

