// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ue_MiniGameV1GameModeBase.h"

#include "PlayerPawn.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/HUD.h>

// �R���X�g���N�^
AUe_MiniGameV1GameModeBase::AUe_MiniGameV1GameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
}


