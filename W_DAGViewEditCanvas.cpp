// Fill out your copyright notice in the Description page of Project Settings.

#include "W_DAGViewEditCanvas.h"
#include "SectionObject.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObjectGameInstance.h"
#include "Slate/SlateBrushAsset.h"

void UW_DAGViewEditCanvas::NativeConstruct()
{
    Super::NativeConstruct();
    bIsDragging = false;

    ListViews = { ListView_Level1 , ListView_Level2, ListView_Level3, ListView_Level4, ListView_Level5 };
    if (GetWorld() && GetWorld()->GetGameInstance())
    {
        USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
        if (GameInstance)
        {
            GameInstance->OnSectionObjectListChanged.AddDynamic(this, &UW_DAGViewEditCanvas::UpdateListViews);
        }
    }
    UpdateListViews();
}


FReply UW_DAGViewEditCanvas::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        bIsDragging = true;
        StartPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
    }
    return FReply::Unhandled();

}
FReply UW_DAGViewEditCanvas::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        CurrentPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
        bIsDragging = false;

        UpdateBorderSelection();

        //StartPosition = FVector2D(0.0f);
        //CurrentPosition = FVector2D(0.0f);
     
    }
    return FReply::Handled();
}
FReply UW_DAGViewEditCanvas::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (bIsDragging)
    {
        CurrentPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
        Invalidate(EInvalidateWidget::LayoutAndVolatility);
        //Invalidate(EInvalidateWidget::LayoutAndVolatility);
        //UpdateBorderPosition();
        
    }
    return FReply::Handled();
}



void UW_DAGViewEditCanvas::UpdateBorderSelection()
{
    //
}

void UW_DAGViewEditCanvas::UpdateListViews()
{
    UE_LOG(LogTemp, Log, TEXT("s Called"));
    if (ListViews.IsEmpty()) return;

    for (UListView* lv : ListViews)
    {
        lv->ClearListItems();
    }
    UE_LOG(LogTemp, Log, TEXT("s Called1"));
    USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    TArray<USectionObject*> SOList = GameInstance->SectionObjectList;
    
    for (USectionObject* Entry : SOList)
    {
        UE_LOG(LogTemp, Log, TEXT("%d"), (Entry->LevelId -1));
        ListViews[Entry->LevelId - 1]->AddItem(Entry);
    }
}

int32 UW_DAGViewEditCanvas::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    int32 NewLayerId = Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

    if (bIsDragging)
    {
        FSlateDrawElement::MakeLines(
            OutDrawElements,
            NewLayerId,
            AllottedGeometry.ToPaintGeometry(),
            TArray<FVector2D>({ StartPosition, CurrentPosition }),
            ESlateDrawEffect::None,
            FLinearColor::Red,
            true,
            2.0f
        );
    }

    return int32();
}
