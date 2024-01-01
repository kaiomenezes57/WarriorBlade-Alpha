// Copyright Epic Games, Inc. All Rights Reserved.

#include "WarriorBladeGameMode.h"
#include "WarriorBladeCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


AWarriorBladeGameMode::AWarriorBladeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	Score = 0;
}

void AWarriorBladeGameMode::SavePoints()
{
	if (SaveGame == NULL) { return; }
	SaveGame->Score = GetPoints();
	UGameplayStatics::SaveGameToSlot(SaveGame, SaveGame->GetName(), 0);
}

UBlueSaveGame* AWarriorBladeGameMode::LoadGame()
{
	SaveGame = Cast<UBlueSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveGame->GetName(), 0));
	return SaveGame;
}