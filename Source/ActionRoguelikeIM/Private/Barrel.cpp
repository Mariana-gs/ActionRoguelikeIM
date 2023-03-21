// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrel.h"
#include "Components/StaticMeshComponent.h"
#include "SMagicProjectile.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABarrel::ABarrel(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshBarrel = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshBarrel");
	//RootComponent = StaticMeshBarrel;
	
	StaticMeshBarrel->SetNotifyRigidBodyCollision(true);
	StaticMeshBarrel->BodyInstance.SetCollisionProfileName("BlockAll");
	StaticMeshBarrel->SetSimulatePhysics(true);

	//Anexando a Função OnComponentHit
	StaticMeshBarrel->OnComponentHit.AddDynamic(this, &ABarrel::OnHit);
	StaticMeshBarrel->SetupAttachment(RootComponent);

	//RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	//RadialForce->SetupAttachment(StaticMeshBarrel);
}


// Called when the game starts or when spawned
void ABarrel::BeginPlay(){
	Super::BeginPlay();
}

// Called every frame
void ABarrel::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

//Destruir Barril 
void ABarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit){

	UE_LOG(LogTemp, Log, TEXT("OnHit in Barrel"));
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);

	ASMagicProjectile* Projectile = Cast<ASMagicProjectile>(OtherActor);
	
	if(Projectile != nullptr) {
		this->Destroy();
		//Projectile->Destroy();
	}
}
