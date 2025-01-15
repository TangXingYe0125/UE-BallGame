// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include <Kismet/KismetSystemLibrary.h>


// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/EnemySphere"), NULL, LOAD_None, NULL);
	m_Sphere->SetStaticMesh(Mesh);
	/*m_Sphere->SetupAttachment(RootComponent);*/

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(m_Sphere);
	Sphere->SetSphereRadius(50.0f);
	m_Sphere->SetupAttachment(RootComponent);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyActor::OnSphereBeginOverlap);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector pos = this->GetActorLocation();
	myrand.initSeed((unsigned int)pos.X+ (unsigned int)pos.Y);
}

void AEnemyActor::GetScore()
{
	APlayerPawn* Player = Cast<APlayerPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Player->AddScore();
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

void AEnemyActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const APlayerPawn* Player = Cast<APlayerPawn>(OtherActor)) {
		this->GetScore();
		this->Destroy();
	}
}




