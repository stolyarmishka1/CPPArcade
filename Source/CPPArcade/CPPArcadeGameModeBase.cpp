// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "CPPArcadeGameModeBase.h"

ACPPArcadeGameModeBase::ACPPArcadeGameModeBase()
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
}
