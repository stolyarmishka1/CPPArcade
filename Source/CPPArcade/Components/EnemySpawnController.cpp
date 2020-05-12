// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnController.h"
#include "Engine/World.h"
#include "TimerManager.h"
// Sets default values for this component's properties
UEnemySpawnController::UEnemySpawnController()
{
	
}


// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	SpawnStage = FEnemySpawnInfo();
	SpawnStage.NumOfEnemy = 10;
	SpawnStage.SpawnDelay = 1.f;

	StartSpawnStage();
}

void UEnemySpawnController::StartSpawnStage()
{
	GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, true, SpawnStage.SpawnDelay);

}

void UEnemySpawnController::SpawnEnemy()
{
	UE_LOG(LogTemp, Log, TEXT("Enemy Spawn"));
	EnemiesSpawned++;
	if(EnemiesSpawned>=SpawnStage.NumOfEnemy)
	{
		GetWorld()->GetTimerManager().ClearTimer(EnemySpawnTimer);
	}
}


