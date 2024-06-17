// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/GridPanel.h"
#include "Components/GridSlot.h"
#include "Components/Border.h"
#include <vector>

#include "W_SelectionBorderCanvas.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_SelectionBorderCanvas : public UUserWidget
{
	GENERATED_BODY()
private:
	// Grid Size
	int32 SizeX;
	int32 SizeY;

	std::vector<std::vector<int>> TileGrid;

	FVector2D StartPosition;
	FVector2D CurrentPosition;
	FVector2D SelectOffset;
	FVector2D SelectSize;
	bool bIsSelecting;

	/* Event handling functions */
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	void UpdateBorderPosition();
	void UpdateBorderSelection();
	 

	/*Grid Generating Functions */
	void SetTileGridValue();

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UBorder* BaseBorder;
	UPROPERTY(meta = (BindWidget))
	UBorder* SelectionBorder;
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* MyUniformGridPanel;
	UPROPERTY(meta = (BindWidget))
	UGridPanel* MyGridPanel;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> BP_SlotEntryRef;

	UFUNCTION(BlueprintCallable)
	void SetGridSize(int32 _SizeX, int32 _SizeY);

	UFUNCTION(BlueprintCallable)
	void MakeGrid() const;

	const std::vector<std::vector<int>>& GetTileGrid() const;

};
