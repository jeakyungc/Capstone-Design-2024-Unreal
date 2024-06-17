// Fill out your copyright notice in the Description page of Project Settings.

#include "W_SelectionBorderCanvas.h"
#include "W_Base.h"
#include "W_GridEntryBorder.h"
#include "Kismet/GameplayStatics.h"
#include "SectionObjectGameInstance.h"


void UW_SelectionBorderCanvas::NativeConstruct()
{
    Super::NativeConstruct();
    bIsSelecting = false;
    
    // Border À§Á¬ Ã£±â
    if (!BaseBorder)
    {
        UE_LOG(LogTemp, Log, TEXT("BaseBorder not Bounded"));
        return;
    }
    if (!SelectionBorder)
    {
        UE_LOG(LogTemp, Log, TEXT("SelectionBorder not Bounded"));
        return;
    }
    SelectionBorder->SetVisibility(ESlateVisibility::Collapsed);
}

FReply UW_SelectionBorderCanvas::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    //UE_LOG(LogTemp, Log, TEXT("MDown"));
    bIsSelecting = true;
    SelectionBorder->SetVisibility(ESlateVisibility::Visible);

    StartPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
    return FReply::Handled();
}

FReply UW_SelectionBorderCanvas::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    //UE_LOG(LogTemp, Log, TEXT("MUp"));
    bIsSelecting = false;
    SelectionBorder->SetVisibility(ESlateVisibility::Collapsed);
    StartPosition = FVector2D(0.0f);
    CurrentPosition = FVector2D(0.0f);

    return FReply::Handled();
}

FReply UW_SelectionBorderCanvas::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (bIsSelecting)
    {
        CurrentPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
        //UE_LOG(LogTemp, Log, TEXT("%s"), *(CurrentPosition.ToString()));
        UpdateBorderPosition();
        UpdateBorderSelection();
    }
    return FReply::Handled();
}

void UW_SelectionBorderCanvas::UpdateBorderPosition()
{
    if (!SelectionBorder) return;
    UCanvasPanelSlot* CanvasSlot = Cast <UCanvasPanelSlot>(SelectionBorder->Slot);

    if (CanvasSlot)
    {
        SelectOffset = FVector2D(
            FMath::Min(CurrentPosition[0], StartPosition[0]), 
            FMath::Min(CurrentPosition[1], StartPosition[1])
        );
        SelectSize = (CurrentPosition - StartPosition).GetAbs();

        CanvasSlot->SetPosition(SelectOffset);
        CanvasSlot->SetSize(SelectSize);
    }
}

void UW_SelectionBorderCanvas::MakeGrid() const
{
    UE_LOG(LogTemp, Log, TEXT("MakeGrid"));
    if (!BP_SlotEntryRef)
    {
        UE_LOG(LogTemp, Error, TEXT("BP_SlotEntryRef is NULL"));
        return;
    }
    if (!MyGridPanel)
    {
        UE_LOG(LogTemp, Error, TEXT("GridPanel Binding is NULL"));
        return;
    }
    
    int32 Size = SizeX * SizeY;
    int32 row = 0;

    if (MyGridPanel->HasAnyChildren())
    {
        UE_LOG(LogTemp, Log, TEXT("Grid has childern"));
        MyGridPanel->ClearChildren();
    }
     
    for (int i = 0; i < Size; i++)
    {
        int32 col = i % SizeX;
        //UW_Button* widget = CreateWidget<UW_Button>(GetWorld(), ButtonRef); //, FName(*buttonId));
        UW_GridEntryBorder* gridEntryBorder = CreateWidget<UW_GridEntryBorder>(GetWorld(), BP_SlotEntryRef);
        UGridSlot* gridSlot = Cast<UGridSlot>(MyGridPanel->AddChildToGrid(gridEntryBorder, row, col));

        gridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
        gridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);

        gridEntryBorder->SetPosition(col, row);
        if (col == SizeX - 1) row++;
    }
}


void UW_SelectionBorderCanvas::UpdateBorderSelection()
{
    FVector2D SelectEnd = SelectOffset + SelectSize;
    FVector2D GridSize = MyUniformGridPanel->GetDesiredSize();
    FVector2D GridEntrySize = GridSize / FVector2D(SizeX, SizeY);

    int32 StartColIndex = static_cast<int32>(SelectOffset.X / GridEntrySize.X);
    int32 StartRowIndex = static_cast<int32>(SelectOffset.Y / GridEntrySize.Y);
    int32 EndColIndex = static_cast<int32>(SelectEnd.X / GridEntrySize.X);
    int32 EndRowIndex = static_cast<int32>(SelectEnd.Y / GridEntrySize.Y);
    //UE_LOG(LogTemp, Log, TEXT("GridSize : %s"), *(GridSize.ToString()));
    //UE_LOG(LogTemp, Log, TEXT("Strat : %d %d, End : %d %d"), StartColIndex, StartRowIndex, EndColIndex, EndRowIndex);

    for (int32 row = StartRowIndex; row <= EndRowIndex; row++)
    {
        for (int32 col = StartColIndex; col <= EndColIndex; col++)
        {
            UW_GridEntryBorder * gridEntryBorder = Cast<UW_GridEntryBorder>(MyGridPanel->GetChildAt(row * SizeX + col));
            USectionObjectGameInstance* GameInstance = Cast<USectionObjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
            gridEntryBorder->SetSectionId(GameInstance->CurrentSectionId);
            gridEntryBorder->ChangeColor(GameInstance->SectionColor);
        }
    }
}


void UW_SelectionBorderCanvas::SetTileGridValue()
{
    const TArray<UPanelSlot*> PanelSlots = MyGridPanel->GetSlots();

    TileGrid = std::vector<std::vector<int>>(SizeY, std::vector<int>(SizeX, 0));
    int32 size = SizeX * SizeY;
    int row = 0;

    for (int i = 0; i < size; i++)
    {
        int32 col = i % SizeX;
        UGridSlot* gridSlot = Cast<UGridSlot>(PanelSlots[i]);

        UW_GridEntryBorder* gridEntryBoder = Cast<UW_GridEntryBorder>(gridSlot->Content);
        TileGrid[row][col] = gridEntryBoder->GetSectionId();

        //		UE_LOG(LogTemp, Log, TEXT("(%d, %d) : %d"), row, col, TileGrid[row][col]);

        if (col == SizeX - 1) row++;
    }
}

void UW_SelectionBorderCanvas::SetGridSize(int32 _SizeX, int32 _SizeY)
{
    SizeX = _SizeX;
    SizeY = _SizeY;
}

const std::vector<std::vector<int>>& UW_SelectionBorderCanvas::GetTileGrid() const
{
    return TileGrid;
}