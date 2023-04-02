// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerBotController.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API APlayerBotController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;
	virtual void Tick(float dt) override;

public:

	void OnHorizontalAxis(float val);
	void OnVerticalAxis(float val);


	
};
