// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTank.h"

// Checks if the AI controller is in the AI tanks
void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank AI BeginPlay has been called"));

	//checks value of PlayerTank
	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Panic! Enemy Tank not found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Tank found: %s"), *ControlledTank->GetName());
	}
}

// Gets the AI controller
ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

// AI tanks find player tank
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();	// finds player tank
	if (!PlayerTank) { return nullptr; }										// protects pointer

	return Cast<ATank>(PlayerTank);


}

