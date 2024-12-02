// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ue_MiniGameV1GameModeBase.h"

#include "PlayerPawn.h"

// コンストラクタ
AUe_MiniGameV1GameModeBase::AUe_MiniGameV1GameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
}

int AUe_MiniGameV1GameModeBase::AddScore(const int32 ScoreNumber)
{
	// 取得した追加する
	m_Score += ScoreNumber;

	return m_Score;
}