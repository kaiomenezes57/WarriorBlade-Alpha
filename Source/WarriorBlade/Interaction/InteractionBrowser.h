// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputAction.h"
#include "WarriorBlade/IDiable.h"
#include "InteractionBrowser.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORBLADE_API UInteractionBrowser : public UActorComponent
{
	GENERATED_BODY()

private:
	UInteractionBrowser();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Raycast();
	void TryToApplyDamage();

	IIDiable* Diable;

public:	
	UPROPERTY(EditAnywhere, Category = "Inputs")
	UInputAction* AttackInputAction;
};