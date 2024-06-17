// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "W_GridEntryBorder.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UW_GridEntryBorder : public UUserWidget
{
	GENERATED_BODY()
private:
	int32 Col;
	int32 Row;
	int32 BorderSectionId;
//protected:
	//virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UBorder* EntryBorder;

	void SetPosition(int32 _Col, int32 _Row);
	void SetSectionId(int _SectionId);
	void ChangeColor(FLinearColor SectionColor);
	int32 GetSectionId() const;
};
