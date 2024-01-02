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
	UpdateText();

	UE_LOG(LogTemp, Warning, TEXT("Mexeu na torre"));
	if (TowerHP < 0) { TowerHP = 0; }
	if (CanDie()) { Die(); }
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	TextRender = FindComponentByClass<UTextRenderComponent>();
	UpdateText();
}

void ATower::UpdateText()
{
	if (!TextRender) { return; }

	FString String = FString::Printf(TEXT("%d/100"), TowerHP);
	TextRender->SetText(FText::FromString(String));
}
