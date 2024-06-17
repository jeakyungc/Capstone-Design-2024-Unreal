// Fill out your copyright notice in the Description page of Project Settings.


#include "W_DAGViewEntry.h"
#include "SectionObject.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObjectGameInstance.h"

void UW_DAGViewEntry::NativeConstruct()
{
	Super::NativeConstruct();

}

void UW_DAGViewEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	USectionObject* SectionObjectRef = Cast<USectionObject>(ListItemObject);
    if (!SectionObjectRef)
    {
        UE_LOG(LogTemp, Error, TEXT("NULL Error"));
        return;
    }

    SectionName->SetText(SectionObjectRef->SectionName);
    USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    int32 Index = GameInstance->SectionObjectList.IndexOfByKey(SectionObjectRef);

    float HueStep = 360.0f / 18;
    float Hue = Index * HueStep;

    FLinearColor NewColor = FLinearColor::MakeFromHSV8(Hue, 255, 255);
    //UE_LOG(LogTemp, Log, TEXT("Size : %d, Query : %d"), GameInstance->SectionObjectList, Index);

    // For DefalutSection
    if (Index == 0)
    {
        NewColor = FLinearColor::FromSRGBColor(FColor::FromHex("#000000"));
    }
    ColorBorder->SetBrushColor(NewColor);
}

