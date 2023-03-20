// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelSpawner.h"
#include "Barrel.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"



// Sets default values
ABarrelSpawner::ABarrelSpawner(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnPointC = CreateDefaultSubobject<USceneComponent>("SpawnPointC");
	SpawnPointR = CreateDefaultSubobject<USceneComponent>("SpawnPointR");
	SpawnPointL = CreateDefaultSubobject<USceneComponent>("SpawnPointL");

}


// Called when the game starts or when spawned
void ABarrelSpawner::BeginPlay(){
	Super::BeginPlay();

	SpawnBarrelScheduled();
}

// Called every frame
void ABarrelSpawner::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

//Agendar o spawn
void ABarrelSpawner::ScheduleBarrelSpawn()
{
	float DeltaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Tempo para o Proximo Spawn: %f"), DeltaToNextSpawn));
	
	GetWorld()->GetTimerManager().SetTimer(Temporizador, this, &ABarrelSpawner::SpawnBarrelScheduled, DeltaToNextSpawn, false);
}

void ABarrelSpawner::SpawnBarrelScheduled()
{
	SpawnBarrel();
	if (ShouldSpawn) {
		ScheduleBarrelSpawn();
	}
}

//Spawnar em um dos tres pontos aleatoriamente
void ABarrelSpawner::SpawnBarrel() {

	//Localização Aleatória
	TArray<USceneComponent*> Scenes = {SpawnPointC, SpawnPointR, SpawnPointL};
	int RIndex = rand() % 3;
	FVector Location = Scenes[RIndex]->GetComponentLocation();
	FRotator Rotation = Scenes[RIndex]->GetComponentRotation();
	
	SpawnRandomBarrel(Location, Rotation);
}

void ABarrelSpawner::SpawnRandomBarrel(FVector Location, FRotator Rotation)
{
	TSubclassOf<AActor> Barrels[] = {Barrel, ExplosiveBarrel};
	int RandIndex = rand() % 2;
	GetWorld()->SpawnActor<AActor>(Barrels[RandIndex], Location, Rotation);
}


void ABarrelSpawner::EndGame(){

	for(TActorIterator<ABarrel> ActorItr(GetWorld()); ActorItr; ++ActorItr){
		ActorItr->Destroy();
	}

	ShouldSpawn = false;
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	//this->Destroy();
}

void ABarrelSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason) {

	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	//GetWorld()->GetTimerManager().ClearTimer(Temporizador);
}
