// Fill out your copyright notice in the Description page of Project Settings.

#include "W_Base.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObject.h"
#include "SectionObjectGameInstance.h"

void UW_Base::NativeConstruct()
{
	Super::NativeConstruct();
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (GameInstance->SectionObjectList.Num() == 0)
		{
			USectionObject* SectionObj = NewObject<USectionObject>();
			GameInstance->SectionObjectList.Add(SectionObj);
		}

		if (GameInstance)
		{
			GameInstance->OnSectionObjectListChanged.AddDynamic(this, &UW_Base::UpdateListView);
		}
	}
	UpdateListView();
}

void UW_Base::UpdateListView()
{
	if (!ListView_Section || !ListView_EditSection) return;

	ListView_Section->ClearListItems();
	ListView_EditSection->ClearListItems();

	USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// Add Defualt Section

	//UE_LOG(LogTemp, Log, TEXT("%s %d %d"), *(DefaultSectionObject->SectionName.ToString()), DefaultSectionObject->TypeId, DefaultSectionObject->LevelId);
	UE_LOG(LogTemp, Log, TEXT("%d"), GameInstance->SectionObjectList.Num());
	TArray<USectionObject*> SOList = GameInstance->SectionObjectList;

	for (USectionObject* Entry : SOList)
	{
		ListView_Section->AddItem(Entry);
		ListView_EditSection->AddItem(Entry);
	}
}
