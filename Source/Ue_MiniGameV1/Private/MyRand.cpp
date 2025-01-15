// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRand.h"

static unsigned int stdRand()
{
	return (rand() % MyRand::MYRAND_MAX) + MyRand::MYRAND_MIN;
}

// �R���X�g���N�^
MyRand::MyRand()
	: _mySeed(0)
{
}

MyRand::~MyRand()
{
}

// �V�[�h�l�̏�����
void MyRand::initSeed(const unsigned int seed)
{
	_mySeed = seed;
}

// �Ǝ�����

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
