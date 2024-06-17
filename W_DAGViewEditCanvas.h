// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "COmponents/ListView.h"
#include "Components/Border.h"

#include "W_DAGViewEditCanvas.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_DAGViewEditCanvas : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UBorder* BaseBorder;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBorder* LineBorder;
	UPROPERTY(meta = (BindWidget))
	UListView* ListView_Level1;
	UPROPERTY(meta = (BindWidget))
	UListView* ListView_Level2;
	UPROPERTY(meta = (BindWidget))
	UListView* ListView_Level3;
	UPROPERTY(meta = (BindWidget))
	UListView* ListView_Level4;
	UPROPERTY(meta = (BindWidget))
	UListView* ListView_Level5;

	TArray<UListView*> ListViews;

	FVector2D StartPosition;
	FVector2D CurrentPosition;
	FVector2D SelectOffset;
	FVector2D SelectSize;
	bool bIsDragging;
	
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual int32 NativePaint
	(
		const FPaintArgs& Args,
		const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements,
		int32 LayerId,
		const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled
	) const override;

	UFUNCTION()
	void UpdateListViews();


	void UpdateBorderSelection();
};
