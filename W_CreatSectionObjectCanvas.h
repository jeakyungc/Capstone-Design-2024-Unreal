// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "Components/EditableTextBox.h"
//#include "Components/Button.h"
//#include "Components/CheckBox.h"
#include "SectionObject.h"
#include "SectionObjectGameInstance.h"
#include "W_CreatSectionObjectCanvas.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_CreatSectionObjectCanvas : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
public:
	UFUNCTION(BlueprintCallable)
	void CreateSectionObjectOnButtonClicked(FText _mSectionName, bool _mTypeId, int32 _mLevelId);
};
