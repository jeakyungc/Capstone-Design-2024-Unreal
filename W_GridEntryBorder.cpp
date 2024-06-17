// Fill out your copyright notice in the Description page of Project Settings.


#include "W_GridEntryBorder.h"

//void UW_GridEntryBorder::NativeConstruct()
//{
//	Super::NativeConstruct();
//}

void UW_GridEntryBorder::SetPosition(int32 _Col, int32 _Row)
{
	Col = _Col;
	Row = _Row;
}

void UW_GridEntryBorder::SetSectionId(int _SectionId)
{
	BorderSectionId = _SectionId;
}

void UW_GridEntryBorder::ChangeColor(FLinearColor SectionColor)
{
    if (EntryBorder)
    {
        EntryBorder->SetBrushColor(SectionColor);
    }
}


int32 UW_GridEntryBorder::GetSectionId() const
{
	return BorderSectionId;
}
