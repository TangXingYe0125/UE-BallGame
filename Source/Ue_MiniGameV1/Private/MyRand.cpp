// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRand.h"

static unsigned int stdRand()
{
	return (rand() % MyRand::MYRAND_MAX) + MyRand::MYRAND_MIN;
}

// コンストラクタ
MyRand::MyRand()
	: _mySeed(0)
{
}

MyRand::~MyRand()
{
}

// シード値の初期化
void MyRand::initSeed(const unsigned int seed)
{
	_mySeed = seed;
}

// 独自乱数

unsigned int MyRand::rand()
{
	unsigned int r = _mySeed * 11111 + 55555;
	_mySeed = r;
	r += r / 128;
	return (r % MYRAND_MAX) + MYRAND_MIN;

}

unsigned int MyRand::randresult()
{
	unsigned int r = _mySeed * 11111 + 55555;
	_mySeed = r;
	r += r / 128;
	return (r % 2) + 0;
}
