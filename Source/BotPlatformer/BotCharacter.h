// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BotCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UBotAnimInstance;

UCLASS()
class BOTPLATFORMER_API ABotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABotCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnVerticalInput(float val);
	void OnHorizontalInput(float val);

	void OnCameraRotate(float val);
	void OnCameraLookUp(float val);

private:
	void UpdateAnimations();

public:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraArm;

private:
	FVector m_CurrInput;

	UBotAnimInstance* m_Animation;
};
