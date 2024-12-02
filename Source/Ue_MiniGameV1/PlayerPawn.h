// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h" // Enhanced Input
#include "InputAction.h" // Enhanced Input
#include "InputActionValue.h" // Enhanced Input
#include "PlayerPawn.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UE_MINIGAMEV1_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for Action input */
	void EventAction(const FInputActionValue& Value);

	/** Called for Axis input */
	void EventAxis(const FInputActionValue& Value);

private:
	// Input�ݒ�
	void SetupInput();

	// Input Event(Action) �C�x���g�n���h���[�֐�
	void PressedAction();
	void ReleasedAction();

	// Input Event(Axis) �C�x���g�n���h���[�֐�
	void PressedMovAxis(const FInputActionValue& Value);
	void PressedCamAxis(const FInputActionValue& Value);

private:
	// Character �p�� StaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> m_Sphere;

	// Camera ��z�u���邽�߂� SpringArm
	UPROPERTY(VisibleAnywhere, Category = m_Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> m_SpringArm;

	// SpringArm �̐�[�ɔz�u����J����
	UPROPERTY(VisibleAnywhere, Category = m_Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> m_Camera;

	// MappingContext
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* m_DefaultMappingContext;

	// Action Input
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* m_ActionInput;

	// Axis Input
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* m_MovAxisInput;

	// Axis Input
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* m_CamAxisInput;

	// Press��Ԃ��Ǘ�
	bool IsPressed = false;

};
