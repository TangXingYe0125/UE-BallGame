// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerPawn.h"
#include "CoreMinimal.h"
#include "MyRand.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

class USphereComponent;

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
	// Character —p‚Ì StaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> m_Sphere;

	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> Sphere;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	MyRand myrand;
	float timer = 0;
	unsigned int direction = 0;
	unsigned int moveX = 1;
	unsigned int moveY = 1;
};



