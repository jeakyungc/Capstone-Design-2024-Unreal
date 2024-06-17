// Fill out your copyright notice in the Description page of Project Settings.

#include "W_CreatSectionObjectCanvas.h"
#include "W_Base.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObjectGameInstance.h"


void UW_CreatSectionObjectCanvas::NativeConstruct()
{
	Super::NativeConstruct();
}

void UW_CreatSectionObjectCanvas::CreateSectionObjectOnButtonClicked(FText _SectionName, bool _TypeId, int32 _LevelId)
{
	USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())); 
	if (GameInstance->SectionObjectList.Num() == 0)
	{
		USectionObject* SectionObj = NewObject<USectionObject>();
		GameInstance->SectionObjectList.Add(SectionObj);
	}
	USectionObject* SectionObj = NewObject<USectionObject>();
	SectionObj->SectionName = _SectionName;
	SectionObj->TypeId = _TypeId;
	SectionObj->LevelId = _LevelId;

	
	GameInstance->SectionObjectList.Add(SectionObj);
	GameInstance->OnSectionObjectListChanged.Broadcast();
}