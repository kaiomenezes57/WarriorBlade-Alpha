// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameTriggerBase.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORBLADE_API AGameTriggerBase : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
};
