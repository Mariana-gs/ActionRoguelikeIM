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

	UFUNCTION(BlueprintCallable)
	void EndGame();

protected:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointC;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointR;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnPointL;

	// Actors classes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ExplosiveBarrel;

	//Spawn Ligado?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShouldSpawn = true;

	//Tempo base entre spawns
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 4.f;

	//Offset de tempo
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 2.f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//Definir um dos tres pontos de spawn aleatoriamente
	UFUNCTION(BlueprintCallable)
	void SpawnBarrel();

	//Agendar o spawn do barril
	UFUNCTION()
	void ScheduleBarrelSpawn();

	//Spawnar barril e agendar o próximo spawn
	UFUNCTION()
	void SpawnBarrelScheduled();

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 

	//Spawnar Barril aleatório, entre explosivo e normal, na localização informada
	UFUNCTION()
	void SpawnRandomBarrel(FVector Location, FRotator Rotation);
	
	FTimerHandle Temporizador;

};
