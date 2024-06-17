// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/Button.h"

#include "W_DAGViewEntry.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_DAGViewEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* SectionName;
	UPROPERTY(meta = (BindWidget))
	UBorder* ColorBorder;
	UPROPERTY(meta = (BindWidget))
	UButton* Button_Node;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
