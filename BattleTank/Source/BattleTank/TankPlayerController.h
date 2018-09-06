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

	// Finds playerController
	ATank* GetPlayerController() const;

	// Begins to move barrel to position where a shot would hit
	// where crosshair intersects the world
	void AimTowardsCrosshair();

	// Returns true crosshair hits landscape and updates OutHitLocation(OutParameter)
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
};
