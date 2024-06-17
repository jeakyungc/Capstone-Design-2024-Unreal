// Copyright Epic Games, Inc. All Rights Reserved.

#include "WFCGameMode.h"
#include "WFCCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWFCGameMode::AWFCGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
