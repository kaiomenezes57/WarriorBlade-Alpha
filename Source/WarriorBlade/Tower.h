// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDiable.h"
#include "Components/TextRenderComponent.h"

#include "Tower.generated.h"
 
DECLARE_MULTICAST_DELEGATE(OnDestroyTower)

UCLASS()
class WARRIORBLADE_API ATower : public AActor, public IIDiable
{
	GENERATED_BODY()

public:
	ATower();

	virtual void ApplyDamage(int Damage) override;
	virtual bool CanDie() override { return TowerHP <= 0; }
	virtual void Die() override { OnDestroyTower.Broadcast(); Destroy(); }

private:
	virtual void BeginPlay() override;
	void UpdateText();

	OnDestroyTower OnDestroyTower;

	UPROPERTY(VisibleAnywhere)
	int TowerHP;
	UPROPERTY(EditAnywhere)
	UTextRenderComponent* TextRender;
};