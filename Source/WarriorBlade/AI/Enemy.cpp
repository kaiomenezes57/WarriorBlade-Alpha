// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Components/PrimitiveComponent.h"
#include "WarriorBlade/Tower.h"
#include "Kismet/GameplayStatics.h"

#include "Components/BoxComponent.h"

AEnemy::AEnemy()
{
	AIControllerClass = AAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetSimulatePhysics(true);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);
	RootComponent = BoxComponent;

	//Setar static mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (CubeMeshAsset.Succeeded()) 
	{
		CubeMesh->SetStaticMesh(CubeMeshAsset.Object); 
		CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		CubeMesh->SetCanEverAffectNavigation(false);
	}

	//Status
	EnemyHP = 50;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	SetDestination();
}

void AEnemy::SetDestination()
{
	AAIController* AIController = Cast<AAIController>(GetController());
	AActor* Tower = UGameplayStatics::GetActorOfClass(GetWorld(), ATower::StaticClass());

	if (AIController == nullptr || Tower == nullptr) { return; }
	AIController->MoveToActor(Tower);
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

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ATower* Tower = Cast<ATower>(OtherActor)) 
	{
		Tower->ApplyDamage(15);
		Destroy();
	}
}