// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetAIController() const;		// Gets the AI controller

	virtual void BeginPlay() override;	// Checks if the AI controller is in the AI tanks

	ATank* GetPlayerTank() const;		// AI tanks find player tank

};
