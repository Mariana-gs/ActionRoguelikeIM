// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelSpawner.h"


// Sets default values
ABarrelSpawner::ABarrelSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPointC = CreateDefaultSubobject<USceneComponent>("SpawnPointC");
	SpawnPointR = CreateDefaultSubobject<USceneComponent>("SpawnPointR");
	SpawnPointL = CreateDefaultSubobject<USceneComponent>("SpawnPointL");

}

// Called when the game starts or when spawned
void ABarrelSpawner::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = SpawnPointL->GetComponentLocation();
	FRotator Rotation = SpawnPointL->GetComponentRotation();
	SpawnActor(Location, Rotation);

	Location = SpawnPointC->GetComponentLocation();
	Rotation = SpawnPointC->GetComponentRotation();
	SpawnActor(Location, Rotation);

	Location = SpawnPointR->GetComponentLocation();
	Rotation = SpawnPointR->GetComponentRotation();
	SpawnActor(Location, Rotation);
}

// Called every frame
void ABarrelSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


bool ABarrelSpawner::SpawnActor(FVector Location, FRotator Rotation) {

	TSubclassOf<AActor> Barrels[] = {Barrel, ExplosiveBarrel};
	int RandIndex = rand() % 2;
	GetWorld()->SpawnActor<AActor>(Barrels[RandIndex], Location, Rotation);

	return true;
}

