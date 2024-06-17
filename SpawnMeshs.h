// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnMeshs.generated.h"

UCLASS()
class WFC_API ASpawnMeshs : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ConveyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> GridPanelClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ASpawnMeshs();

	// Called every frame
	virtual void Tick(float DeltaTime) override;



	void SpwanItem(UClass* ItemToSpawn);
};
