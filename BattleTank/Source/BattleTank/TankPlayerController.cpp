// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Player BeginPlay has been called"));

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

