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
	// Herdado por meio de IIDiable
	void ApplyDamage(int Damage) override;
	bool CanDie() override { return EnemyHP <= 0; }
	void Die() override { UE_LOG(LogTemp, Warning, TEXT("Morreu!")); }

private:
	virtual void BeginPlay() override;
	bool InitialConfiguration();
	void SetDestination(const FVector& Position);

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Enemy")
	int EnemyHP;

	UBoxComponent* BoxComponent;
	AActor* Destination;
};