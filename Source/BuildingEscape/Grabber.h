// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead the player can reach in centimeters 
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab whats in reach
	void Grab();
	// When grab is released
	void Release();
	// Find (Assume) Attached physics handle
	void FindPhysicsHandleComponent();
	// Setup (Assume) Attached Input Component
	void SetupInputComponent();

	// Return hit for first physics body in reach 
	const FHitResult GetFirstPhysicsBodyInReach();

	FVector GetReachLineStart();

	// Return Current end of reach line
	FVector GetReachLineEnd();

};
