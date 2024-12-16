// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "playerpawn.h"
#include"Components/SphereComponent.h"
// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/EnemySphere"), NULL, LOAD_None, NULL);
	m_Sphere->SetStaticMesh(Mesh);
	m_Sphere->SetupAttachment(RootComponent);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radiusを設定する
	Sphere->SetSphereRadius(50.0f);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnSphereBeginOverlap);

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	MyRand myrand;
	myrand.initSeed((unsigned int)time(NULL));
	Super::Tick(DeltaTime);

	FVector pos = this->GetActorLocation();
	pos.X += myrand.rand();
	pos.X -= myrand.rand();
	pos.Y += myrand.rand();
	pos.Y -= myrand.rand();
	pos.X = FMath::Clamp(pos.X, -4000, 4000);
	pos.Y = FMath::Clamp(pos.Y, -4000, 4000);
	this->SetActorLocation(pos);
	
}





//==========================================================================
// 関数定義

// 標準関数の疑似乱数
static unsigned int stdRand()
{
	return (rand() % MyRand::MYRAND_MAX) + MyRand::MYRAND_MIN;
}

//==========================================================================
// メソッド定義

// コンストラクタ
MyRand::MyRand()
	: _mySeed(0)
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
	// ↓岸オリジナルの乱数計算
	unsigned int r = _mySeed * 11111 + 55555;
	_mySeed = r;
	r += r / 128;
	return (r % MYRAND_MAX) + MYRAND_MIN;
}
