// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "AI/Enemy.h"

AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Time = 0;
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;
	
	if (Time < 10) { return; }
	if (CanSpawn()) 
	{
		Spawn();
	}

	Time = 0;
}

void AEnemySpawner::Spawn()
{
    UWorld* World = GetWorld();

    if (World)
    {
        FVector SpawnLocation = GetActorLocation();
        FRotator SpawnRotation = GetActorRotation();
        World->SpawnActor<AEnemy>(AEnemy::StaticClass(), SpawnLocation, SpawnRotation);
    }
}
