// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay has been called"));

	auto ControlledTank = GetPlayerController();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Panic! Tank not found."));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found: %s"), *ControlledTank->GetName());
	}




}

ATank* ATankPlayerController::GetPlayerController() const
{
	return Cast<ATank>(GetPawn());
}

