// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ue_MiniGameV1GameModeBase.h"

#include "PlayerPawn.h"

// �R���X�g���N�^
AUe_MiniGameV1GameModeBase::AUe_MiniGameV1GameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
}

int AUe_MiniGameV1GameModeBase::AddScore(const int32 ScoreNumber)
{
	// �擾�����ǉ�����
	m_Score += ScoreNumber;

	return m_Score;
}