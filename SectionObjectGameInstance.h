// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SectionObject.h"
#include "DAGraph.h"
#include "SectionObjectGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSectionObjectListChanged);
/**
 * 
 */
UCLASS()
class WFC_API USectionObjectGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	TArray<USectionObject*> SectionObjectList;
	int32 CurrentSectionId = 0;
	int32 SectionIdCnt = 0;
	FLinearColor SectionColor = FLinearColor::FromSRGBColor(FColor::FromHex("#000000"));

	UPROPERTY(BlueprintAssignable)
	FOnSectionObjectListChanged OnSectionObjectListChanged;
};
