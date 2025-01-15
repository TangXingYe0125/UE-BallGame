// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE_MINIGAMEV1_API MyRand
{
public:

	static const int MYRAND_MIN = 1;		// 乱数最小値
	static const int MYRAND_MAX = 10;		// 乱数最大値

	//----------------------------------------------------------------------
	// メソッド

	MyRand();								// コンストラクタ
	~MyRand();
	void initSeed(const unsigned int seed);	// シード値の初期化
	unsigned int rand();					// 独自乱数
	unsigned int randresult();
private:
	//----------------------------------------------------------------------
	// フィールド
	unsigned int _mySeed = 0;		// 独自乱数のランダムシード値
};
