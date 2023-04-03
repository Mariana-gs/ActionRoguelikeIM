// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMagicProjectile.h"
#include "GameFramework/Actor.h"
#include "SDashProjectile.generated.h"

UCLASS()
class ACTIONROGUELIKEIM_API ASDashProjectile : public ASMagicProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASDashProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonateDelay;

	FTimerHandle TimerHandle_DelayedDetonate;

	void Explode();

	void TeleportInstigator();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
