// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Components/Button.h"

#include "W_Base.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_Base : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

public:

	/* Widget Bindings */
	UPROPERTY(meta=(BindWidget))
	UListView* ListView_Section;

	UPROPERTY(meta = (BindWidget))
	UListView* ListView_EditSection;

	/*UPROPERTY(meta = (BindWidget))
	UListView* ListView_Section;*/

	UFUNCTION(BlueprintCallable)
	void UpdateListView();

	//UFUNCTION(BlueprintCallable)
	//int32 AddSectionObject(USectionObject* _SectionObject);

	//UFUNCTION(BlueprintCallable)
	//void RemoveSectionObject(USectionObject* _SectionObject);
};
