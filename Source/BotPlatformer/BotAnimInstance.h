// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BotAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOTPLATFORMER_API UBotAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Properties");
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Properties");
	bool Grounded;

	FORCEINLINE void SetSpeed(float speed) { Speed = speed; }

private:
	
};
