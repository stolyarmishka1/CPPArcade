// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent()
	:
ShootPeriod(1.f)
{

	
}


// Called when the game starts
void UShootComponent::BeginPlay()
{
	Super::BeginPlay();
	StartShoting();
	
	
}

void UShootComponent::Shoot()
{
	

	for(FShootInfo ShootInfo:ShootInfos)
	{
		
		FActorSpawnParameters SpawnParameters;

		FVector SpawnLocation = GetOwner()->GetActorLocation() + GetOwner()->GetActorRotation().RotateVector(ShootInfo.Offset);
		
		FRotator SpawnRotation = GetOwner()->GetActorRotation();
		SpawnRotation.Add(0.f, ShootInfo.Angle, 0.f);

		GetWorld()->SpawnActor<AShootProjectile>(ShootInfo.ProjectileClass, SpawnLocation,SpawnRotation, SpawnParameters);
	}
}

void UShootComponent::StartShoting()
{
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent::Shoot,ShootPeriod, true, ShootPeriod);
}

void UShootComponent::StopShoting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}


