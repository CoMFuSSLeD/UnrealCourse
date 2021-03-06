// Copyright Joe Fernandez 2016

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	// How far ahead a player can reach
	float Reach = 100.f;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	// Ray-cast and grab what's in reach
	void Grab();
	void Release();

	// Find (assumed) attached physics handle
	void FindPhysicsHandleComponent();

	// Setup (assumed) attached input component
	void SetupInputComponent();

	// Return hit for physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Get Player's start of reach point
	FVector GetReachLineStart();

	// Get Player's end of reach distance
	FVector GetReachLineEnd();
};
