// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "BlueSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORBLADE_API UBlueSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UBlueSaveGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int Score;
};
