// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectile.h"
#include "SBlackholeProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKEIM_API ASBlackholeProjectile : public ASProjectile
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ParticleComp;

	
};
