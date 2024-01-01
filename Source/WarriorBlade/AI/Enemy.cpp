// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "WarriorBlade/Tower.h"
#include "Kismet/GameplayStatics.h"

#include "Components/BoxComponent.h"

AEnemy::AEnemy()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	AIControllerClass = AAIController::StaticClass();
}

void AEnemy::ApplyDamage(int Damage)
{
	EnemyHP -= Damage;

	if (CanDie())
	{
		EnemyHP = 0;
		Die();
	}
}

void AEnemy::BeginPlay()
{	
	Super::BeginPlay();
	Destination = UGameplayStatics::GetActorOfClass(GetWorld(), ATower::StaticClass());
	SetDestination(Destination->GetActorLocation());
}

void AEnemy::SetDestination(const FVector& Position)
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController == nullptr) { return; }
	AIController->MoveToLocation(Position);
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATower* Tower = Cast<ATower>(OtherActor);
	if (Tower == nullptr) { return; }

	Tower->ApplyDamage(50);
	Destroy();
}