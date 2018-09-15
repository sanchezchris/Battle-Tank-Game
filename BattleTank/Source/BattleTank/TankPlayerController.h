// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"		// last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:

	// runs when game starts
	virtual void BeginPlay() override;

	// called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Finds playerController
	ATank* GetPlayerController() const;

	// Begins to move barrel to position where a shot would hit
	// where crosshair intersects the world
	void AimTowardsCrosshair();

	// Returns true when crosshair hits landscape and updates OutHitLocation(OutParameter)
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceLength = 1000000;


	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};