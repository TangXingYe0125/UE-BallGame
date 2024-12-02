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
	// Character 用の StaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> m_Sphere;
};

//==========================================================================
// 独自疑似乱数クラス
class MyRand
{
public:
	//----------------------------------------------------------------------
	// 定数

	static const int MYRAND_MIN = 1;		// 乱数最小値
	static const int MYRAND_MAX = 20;		// 乱数最大値

	//----------------------------------------------------------------------
	// メソッド

	MyRand();								// コンストラクタ
	void initSeed(const unsigned int seed);	// シード値の初期化
	unsigned int rand();					// 独自乱数

private:
	//----------------------------------------------------------------------
	// フィールド
	unsigned int _mySeed = 0;		// 独自乱数のランダムシード値
};



