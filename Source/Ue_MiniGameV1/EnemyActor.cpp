// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// 標準関数の疑似乱数
static unsigned int stdRand()
{
	return (rand() % MyRand::MYRAND_MAX) + MyRand::MYRAND_MIN;
}

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

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector pos = this->GetActorLocation();
	myrand.initSeed((unsigned int)pos.X+ (unsigned int)pos.Y);
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector pos = this->GetActorLocation();

	timer += DeltaTime;
	if (timer <= 1.0f)
	{
		pos.X = direction == 0 ? pos.X + moveX : pos.X - moveX;
		pos.Y = direction == 0 ? pos.Y + moveY : pos.Y - moveY;
	}
	else
	{
		timer = 0;
		direction = myrand.randresult();
		moveX = myrand.rand();
		moveY = myrand.rand();
	}

	pos.X = FMath::Clamp(pos.X, -4000, 4000);
	pos.Y = FMath::Clamp(pos.Y, -4000, 4000);
	this->SetActorLocation(pos);	

}

