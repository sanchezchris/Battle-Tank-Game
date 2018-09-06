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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetPlayerController() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{

	if (!GetPlayerController()) { return; }
	FVector HitLocation;		// Out parameter

	if (GetSightRayHitLocation(HitLocation)) 
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Aiming at point: %s"), *HitLocation.ToString());
		// TODO: Tell Tank to aim at this location

	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}

