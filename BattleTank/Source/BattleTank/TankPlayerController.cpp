// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

// Runs when game starts
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

// Runs every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

// Returns player controller pawn
ATank* ATankPlayerController::GetPlayerController() const
{
	return Cast<ATank>(GetPawn());
}

// Aims towards targeting reticle
void ATankPlayerController::AimTowardsCrosshair() 
{

	if (!GetPlayerController()) { return; }
	FVector HitLocation;		// Out parameter

	if (GetSightRayHitLocation(HitLocation)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming at location: %s"), *HitLocation.ToString());
		// TODO: Tell Tank to aim at this location

	}
}

// sets up targeting reticle space and size, calls analzying functions
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// viewport X and Y values
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// find location of aiming reticle on screen
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// Calls GetLookDirection
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}

// "Deprojects" ScreenLocation to the world, finds camera location and pointing direction 
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;	// Will be disgarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection
	);
}

// Draws line Trace, returns true if collides with something visible, updates HitLocation
bool ATankPlayerController::GetVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceLength);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}

