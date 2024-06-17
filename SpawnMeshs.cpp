// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnMeshs.h"

// Sets default values
ASpawnMeshs::ASpawnMeshs()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ASpawnMeshs::BeginPlay()
{
	Super::BeginPlay();
	SpwanItem(ConveyClass);
}

// Called every frame
void ASpawnMeshs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnMeshs::SpwanItem(UClass* ItemToSpawn)
{
	GetWorld()->SpawnActor<AActor>(ItemToSpawn, FVector(0.f), FRotator(0.f));
}

