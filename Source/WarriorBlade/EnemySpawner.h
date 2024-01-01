// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class WARRIORBLADE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
private:
	AEnemySpawner();
	virtual void Tick(float DeltaTime) override;
	void Spawn();
	bool CanSpawn() { return FMath::RandRange(0, 100) <= Chance; }

	UPROPERTY(EditAnywhere)
	int Chance;

	UPROPERTY(VisibleAnywhere)
	float Time;
};
