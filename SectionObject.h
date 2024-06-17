// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SectionObject.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API USectionObject : public UObject
{
	GENERATED_BODY()

public:
	FText SectionName = FText::FromString("EmptySection");
	bool TypeId = false;
	int32 LevelId = 1;
};
