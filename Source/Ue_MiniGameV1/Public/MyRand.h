// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE_MINIGAMEV1_API MyRand
{
public:

	static const int MYRAND_MIN = 1;		// �����ŏ��l
	static const int MYRAND_MAX = 10;		// �����ő�l

	//----------------------------------------------------------------------
	// ���\�b�h

	MyRand();								// �R���X�g���N�^
	~MyRand();
	void initSeed(const unsigned int seed);	// �V�[�h�l�̏�����
	unsigned int rand();					// �Ǝ�����
	unsigned int randresult();
private:
	//----------------------------------------------------------------------
	// �t�B�[���h
	unsigned int _mySeed = 0;		// �Ǝ������̃����_���V�[�h�l
};
