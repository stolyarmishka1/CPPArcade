// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawnController.generated.h"

USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		TSubclassOf<APawn> ProjectileClass;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
		FTransform SpawnTransform;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
			int NumOfEnemy;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
			float SpawnDelay;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPARCADE_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemySpawnController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void StartSpawnStage();
	
	void SpawnEnemy();
	
	FEnemySpawnInfo SpawnStage;

	int EnemiesSpawned;
	
	FTimerHandle ChangeStageTimer;
	FTimerHandle EnemySpawnTimer;
public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	TArray<FEnemySpawnInfo> SpawnStages;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	float StageMinDelay;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	float StageMaxDelay;
};
