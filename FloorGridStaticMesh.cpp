// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorGridStaticMesh.h"

void AFloorGridStaticMesh::ChangeScale(int32 SizeX, int32 SizeY)
{	
	float ScaleX = SizeX / 10.0;
	float ScaleY = SizeY / 10.0;
	FVector ScaleVector = FVector(ScaleX, ScaleY, 1.0);
	
	FVector NewScale = FVector(1.0, 1.0, 1.0) * ScaleVector;
	FVector NewLocation = FVector(500.0, 500.0, 0.0) * ScaleVector;

	SetActorScale3D(NewScale);
	SetActorLocation(NewLocation);
	UE_LOG(LogTemp, Log, TEXT("Actor location : %s"), *NewLocation.ToString());
	UE_LOG(LogTemp, Log, TEXT("Actor Scale : %s"), *NewScale.ToString());
}