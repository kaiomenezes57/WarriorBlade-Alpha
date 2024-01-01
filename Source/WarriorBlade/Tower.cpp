// Fill out your copyright notice in the Description page of Project Settings.
#include "Tower.h"

ATower::ATower()
{
	PrimaryActorTick.bCanEverTick = false;
	TowerHP = 100;
}

void ATower::ApplyDamage(int Damage)
{
	TowerHP -= Damage;

	UE_LOG(LogTemp, Warning, TEXT("Torre tomou dano"));
	if (TowerHP < 0) { TowerHP = 0; }
	if (CanDie()) { Die(); }
}