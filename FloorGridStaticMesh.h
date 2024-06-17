// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "FloorGridStaticMesh.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API AFloorGridStaticMesh: public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ChangeScale(int32 SizeX, int32 SizeY);
};
