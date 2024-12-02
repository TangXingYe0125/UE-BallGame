// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ue_MiniGameV1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_MINIGAMEV1_API AUe_MiniGameV1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// �R���X�g���N�^
	AUe_MiniGameV1GameModeBase();
	int m_Score = 0;
	int AddScore(const int32 ScoreNumber);

};
