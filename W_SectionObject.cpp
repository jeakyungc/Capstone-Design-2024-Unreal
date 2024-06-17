// Fill out your copyright notice in the Description page of Project Settings.

#include "W_SectionObject.h"
#include "SectionObject.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObjectGameInstance.h"


void UW_SectionObject::NativeConstruct()
{
    Super::NativeConstruct();
    if (SelectButton)
    {
        SelectButton->OnClicked.AddDynamic(this, &UW_SectionObject::OnClickSectionButton);
        
    }
    if (DelButton)
    {
        DelButton->OnClicked.AddDynamic(this, &UW_SectionObject::OnClickDelButton);
    }
}

void UW_SectionObject::OnClickSectionButton()
{
    USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

    FText SelectedSectionText = ButtonText->GetText();
    int32 Index = 0;
    for (USectionObject* Entry : GameInstance->SectionObjectList)
    {
        if (Entry->SectionName.EqualTo(SelectedSectionText)) break;
        Index++;
    }

    if (Index != INDEX_NONE) {
        GameInstance->CurrentSectionId = Index;
        UE_LOG(LogTemp, Log, TEXT("%d"), GameInstance->CurrentSectionId);
        FLinearColor NewColor = ColorBorder->GetBrushColor();
        GameInstance->SectionColor = NewColor;
    }
}

void UW_SectionObject::OnClickDelButton()
{
    //UE_LOG(LogTemp, Log, TEXT("Delete Button clicked"));
    USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

    FText SelectedSectionText = ButtonText->GetText();
    int32 Index = 0;
    for (USectionObject* Entry : GameInstance->SectionObjectList)
    {
        if (Entry->SectionName.EqualTo(SelectedSectionText)) break;
        Index++;
    }

    if (Index != INDEX_NONE) {
        GameInstance->SectionObjectList.RemoveAt(Index);
        GameInstance->OnSectionObjectListChanged.Broadcast();
        UE_LOG(LogTemp, Log, TEXT("Remain : %d"), GameInstance->SectionObjectList.Num());
    }
}

void UW_SectionObject::NativeOnListItemObjectSet(UObject* ListItemObject)
{
    USectionObject* SectionObjectRef = Cast<USectionObject>(ListItemObject);
    if (!SectionObjectRef) 
    {
        UE_LOG(LogTemp, Error, TEXT("NULL Error"));
        return;
    }

    ButtonText->SetText(SectionObjectRef->SectionName);
    //UE_LOG(LogTemp, Log, TEXT("Name : %s"), *(SectionObjectRef->SectionName.ToString()));
    TypeText->SetText(SectionObjectRef->TypeId == true ? FText::FromString("Line") : FText::FromString("Area"));
    LevelText->SetText(FText::AsNumber(SectionObjectRef->LevelId));

    //Set BorderColor
    USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())); 
    int32 Index = GameInstance->SectionObjectList.IndexOfByKey(SectionObjectRef);
    
    float HueStep = 360.0f / 10;
    float Hue = Index * HueStep;

    FLinearColor NewColor = FLinearColor::MakeFromHSV8(Hue, 255, 255);
    //UE_LOG(LogTemp, Log, TEXT("Size : %d, Query : %d"), GameInstance->SectionObjectList, Index);

    // For DefalutSection
    if (Index == 0)
    {
        DelButton->SetVisibility(ESlateVisibility::Collapsed);
        NewColor = FLinearColor::FromSRGBColor(FColor::FromHex("#000000"));
    }
    ColorBorder->SetBrushColor(NewColor);
}