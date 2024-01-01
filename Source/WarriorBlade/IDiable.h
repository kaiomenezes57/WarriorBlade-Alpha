// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "IDiable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UIDiable : public UInterface
{
	GENERATED_BODY()
};

class WARRIORBLADE_API IIDiable 
{
    GENERATED_BODY()

public:
    virtual void ApplyDamage(int Damage) = 0;
    virtual bool CanDie() = 0;
    virtual void Die() = 0;
};