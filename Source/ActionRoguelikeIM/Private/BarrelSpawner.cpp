// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelSpawner.h"
#include "Barrel.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"



// Sets default values
ABarrelSpawner::ABarrelSpawner(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPointC = CreateDefaultSubobject<USceneComponent>("SpawnPointC");
	SpawnPointR = CreateDefaultSubobject<USceneComponent>("SpawnPointR");
	SpawnPointL = CreateDefaultSubobject<USceneComponent>("SpawnPointL");

}


// Called when the game starts or when spawned
void ABarrelSpawner::BeginPlay(){
	Super::BeginPlay();

	FTimerHandle Temporizador;
	GetWorldTimerManager().SetTimer(Temporizador, this, FTimerDelegate::TUObjectMethodDelegate<ABarrelSpawner>::FMethodPtr(&ABarrelSpawner::SpawnBarrels), 2.f, true);
}

// Called every frame
void ABarrelSpawner::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

void ABarrelSpawner::SpawnBarrels() {

	TArray<USceneComponent*> Scenes = {SpawnPointC, SpawnPointR, SpawnPointL};
	int RIndex = rand() % 3;
	FVector Location = Scenes[RIndex]->GetComponentLocation();
	FRotator Rotation = Scenes[RIndex]->GetComponentRotation();

	TSubclassOf<AActor> Barrels[] = {Barrel, ExplosiveBarrel};
	int RandIndex = rand() % 2;

	GetWorld()->SpawnActor<AActor>(Barrels[RandIndex], Location, Rotation);
}



void ABarrelSpawner::EndGame(){
	for(TActorIterator<ABarrel> ActorItr(GetWorld()); ActorItr; ++ActorItr){
		ActorItr->Destroy();
	}
	this->Destroy();
}

