// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrelSpawner.generated.h"

UCLASS()
class ACTIONROGUELIKEIM_API ABarrelSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrelSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Minutes = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Seconds = 00.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointC;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointR;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointL;


	UFUNCTION(BlueprintCallable)
	bool SpawnActor(FVector Location, FRotator Rotation);

	// Actor class to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ExplosiveBarrel;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
