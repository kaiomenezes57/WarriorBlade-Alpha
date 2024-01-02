// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WarriorBlade/IDiable.h"
#include "Components/BoxComponent.h"

#include "Enemy.generated.h"

UCLASS()
class WARRIORBLADE_API AEnemy : public APawn, public IIDiable
{
	GENERATED_BODY()

public:	
	AEnemy();
	virtual void BeginPlay() override;

	// Herdado por meio de IIDiable
	void ApplyDamage(int Damage) override;
	bool CanDie() override { return EnemyHP <= 0; }
	void Die() override { Destroy(); }

private:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void SetDestination();

	UPROPERTY(VisibleAnywhere, Category = "Enemy")
	int EnemyHP;

	UPROPERTY(VisibleAnywhere, Category = "Enemy")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Enemy")
	UStaticMeshComponent* CubeMesh;
};