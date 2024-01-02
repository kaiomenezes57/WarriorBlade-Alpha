// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionBrowser.h"
#include "DrawDebugHelpers.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

UInteractionBrowser::UInteractionBrowser() 
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    PrimaryComponentTick.bAllowTickOnDedicatedServer = true;
}

void UInteractionBrowser::BeginPlay()
{
	Super::BeginPlay();

    if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
    {
        if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
        {
            EnhancedInputComponent->BindAction(AttackInputAction, ETriggerEvent::Started, this, &UInteractionBrowser::TryToApplyDamage);
        }
    }
}

void UInteractionBrowser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    Raycast();
}

void UInteractionBrowser::Raycast()
{
    FVector Start = GetOwner()->GetActorLocation();
    FVector End = Start + (GetOwner()->GetActorForwardVector() * 200);
    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
    {
        Diable = Cast<IIDiable>(HitResult.GetActor());
        if (Diable)
        {
            DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1.0f);
            return;
        }
    }

    Diable = nullptr;
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0.1f, 0, 1.0f);
}

void UInteractionBrowser::TryToApplyDamage()
{
    if (Diable) {
        Diable->ApplyDamage(25);
    }
}