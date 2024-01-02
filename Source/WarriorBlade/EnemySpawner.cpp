// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "AIController.h"
#include "AI/Enemy.h"

AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	Time = 0;
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;

	if (Time < 20) { return; }
	if (CanSpawn()) 
	{
		Spawn();
	}

	Time = 0;
}

void AEnemySpawner::Spawn()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();
	
	GetWorld()->SpawnActor<AEnemy>(EnemyBP, SpawnLocation, SpawnRotation);
}