// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.h"
#include "SMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;


UCLASS()
class ACTIONROGUELIKEIM_API ASMagicProjectile : public ASProjectile
{
	GENERATED_BODY()
	
public:	
	
	ASMagicProjectile();

protected:

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent * OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
