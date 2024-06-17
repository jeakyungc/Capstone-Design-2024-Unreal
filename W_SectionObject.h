// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "W_Base.h"

#include "W_SectionObject.generated.h"

/**
 * SectionObject를 Widget으로 표현
 */
UCLASS()
class WFC_API UW_SectionObject : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* ButtonText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TypeText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelText;
	UPROPERTY(meta = (BindWidget))
	UBorder* ColorBorder;
	UPROPERTY(meta = (BindWidget))
	UButton* SelectButton;
	UPROPERTY(meta = (BindWidget))
	UButton* DelButton;


	UFUNCTION()
	void OnClickSectionButton();
	UFUNCTION()
	void OnClickDelButton();
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	//UObject* GetListItemObjectInternal() const;
	//void SetListItemObject(UObject* InObject);
};
