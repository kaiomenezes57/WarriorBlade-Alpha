// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SaveLoad/BlueSaveGame.h"

#include "WarriorBladeGameMode.generated.h"

UCLASS(minimalapi)
class AWarriorBladeGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	int Score;
	UBlueSaveGame* SaveGame;
	
	UBlueSaveGame* LoadGame();
	void SavePoints();

public:
	AWarriorBladeGameMode();

	void AddPoints(int Amount) { Score += Amount; }
	void RemovePoints(int Amount) { Score -= Amount; }
	int GetPoints() const { return Score; }
};