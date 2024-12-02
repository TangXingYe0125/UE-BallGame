// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class UE_MINIGAMEV1_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Character �p�� StaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> m_Sphere;
};

//==========================================================================
// �Ǝ��^�������N���X
class MyRand
{
public:
	//----------------------------------------------------------------------
	// �萔

	static const int MYRAND_MIN = 1;		// �����ŏ��l
	static const int MYRAND_MAX = 20;		// �����ő�l

	//----------------------------------------------------------------------
	// ���\�b�h

	MyRand();								// �R���X�g���N�^
	void initSeed(const unsigned int seed);	// �V�[�h�l�̏�����
	unsigned int rand();					// �Ǝ�����

private:
	//----------------------------------------------------------------------
	// �t�B�[���h
	unsigned int _mySeed = 0;		// �Ǝ������̃����_���V�[�h�l
};



