// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	/***************
	void OpenDoor();
	void CloseDoor();
	***************/

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

private:
	// Coding without Blueprint
	/**********************
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;
	***********************/

	// When set to EditAnywhere have the ability to change it inside of Unreal Engine
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate= nullptr;

	float TriggerMass = 35.f;
	float TriggerMassMax = 70.f;

	// Coding without Blueprint
	/*
	UPROPERTY(EditAnywhere)
	float DoorClosedDelay = 1.f;
	*/

	float LastDoorOpenTime;

	//UPROPERTY(EditAnywhere)

	AActor* Owner = nullptr; //the owning door

	// Return total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
