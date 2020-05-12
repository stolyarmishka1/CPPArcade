// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPPArcade/Components/EnemySpawnController.h"
#include "CPPArcadeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPARCADE_API ACPPArcadeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
		ACPPArcadeGameModeBase();
public:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
		UEnemySpawnController* EnemySpawnController;
};
