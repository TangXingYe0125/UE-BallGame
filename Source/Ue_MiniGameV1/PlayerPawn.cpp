///https://nathan-ag.itch.io/belus-dungeon

// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetSystemLibrary.h" // Enhanced Input
#include "Kismet/GameplayStatics.h" // Enhanced Input
#include "Components/InputComponent.h" // Enhanced Input
#include "EnhancedInputComponent.h" // Enhanced Input
#include "EnhancedInputSubsystems.h" // Enhanced Input

// Sets default values
APlayerPawn::APlayerPawn()
{
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Pawn

	// ãÖÇçÏÇÈ
	m_Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = m_Sphere;
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/PlayerSphere"), NULL, LOAD_None, NULL);
	m_Sphere->SetStaticMesh(Mesh);

	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
	m_Sphere->SetSimulatePhysics(true);
	m_Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));
	m_Sphere->BodyInstance.bNotifyRigidBodyCollision = true;
	// SpringArm Çí«â¡Ç∑ÇÈ
	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	m_SpringArm->SetupAttachment(RootComponent);

	// äpìxÇïœçXÇ∑ÇÈ FRotator(Pitch(Y), Yaw(Z), Roll(X))
	m_SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// SpringArm ÇÃí∑Ç≥Çí≤êÆÇ∑ÇÈ
	m_SpringArm->TargetArmLength = 450.0f;

	// // m_SpringArm Ç©ÇÁÇÃäpìxÇåpè≥ÇµÇ»Ç¢
	// m_SpringArm->bInheritPitch = false;
	// m_SpringArm->bInheritYaw = false;
	// m_SpringArm->bInheritRoll = false;

	// CameraÇÃLagÇóLå¯Ç…Ç∑ÇÈ
	m_SpringArm->bEnableCameraLag = true;


	// CameraÇí«â¡Ç∑ÇÈ
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	m_Camera->SetupAttachment(m_SpringArm);

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Enhaced Input

	// Input ActionÇì«çû
	m_ActionInput = LoadObject<UInputAction>(NULL, TEXT("/Game/IA_Action"), NULL, LOAD_None, NULL);
	m_MovAxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/IA_MovAxis"), NULL, LOAD_None, NULL);
	m_CamAxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/IA_CamAxis"), NULL, LOAD_None, NULL);

	// Input Mapping ContextÇì«çû
	m_DefaultMappingContext = LoadObject<UInputMappingContext>(NULL, TEXT("/Game/IMC_Default"), NULL, LOAD_None, NULL);
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// Inputê›íËÇçsÇ§
	SetupInput();

}


void APlayerPawn::SetupInput()
{
	// PlayerControllerÇéÊìæÇ∑ÇÈ
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// ì¸óÕÇóLå¯Ç…Ç∑ÇÈ
	EnableInput(controller);

	if (InputComponent)
	{
		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

			// Input Action
			EnhancedInputComponent->BindAction(m_ActionInput, ETriggerEvent::Triggered, this, &APlayerPawn::PressedAction);
			EnhancedInputComponent->BindAction(m_ActionInput, ETriggerEvent::Completed, this, &APlayerPawn::ReleasedAction);

			// Input Axis
			EnhancedInputComponent->BindAction(m_MovAxisInput, ETriggerEvent::Triggered, this, &APlayerPawn::PressedMovAxis);

			// Input Axis Cam
			EnhancedInputComponent->BindAction(m_CamAxisInput, ETriggerEvent::Triggered, this, &APlayerPawn::PressedCamAxis);
		}

		// Input Mapping ContextÇìoò^Ç∑ÇÈ
		if (APlayerController* PlayerController = Cast<APlayerController>(controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(m_DefaultMappingContext, 0);
			}
		}
	}
}

void APlayerPawn::PressedAction()
{
	if (!IsPressed)
	{
		// Pressed
		UKismetSystemLibrary::PrintString(this, TEXT("Pressed"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

		// PressèÛë‘Ç…ê›íË
		IsPressed = true;
	}
}

void APlayerPawn::ReleasedAction()
{
	// Released
	UKismetSystemLibrary::PrintString(this, TEXT("Released"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// PressèÛë‘Çâèú
	IsPressed = false;
}

void APlayerPawn::PressedMovAxis(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D v = Value.Get<FVector2D>();

	// Axis Input Value
	//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("V X:%f Y:%f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// ÉJÉÅÉââÒì]ÇîΩâf
	FMinimalViewInfo MinimalViewInfo;
	m_Camera->GetCameraView(0.0f, MinimalViewInfo);
	FMatrix ViewRotationMatrix = FInverseRotationMatrix(MinimalViewInfo.Rotation) * FMatrix(
		FPlane(0, 0, 1, 0),
		FPlane(1, 0, 0, 0),
		FPlane(0, 1, 0, 0),
		FPlane(0, 0, 0, 1));
	FVector d = { v.X, v.Y, 0.0 };
	d = ViewRotationMatrix.Rotator().RotateVector(d);


	// à⁄ìÆ
	FVector pos = this->GetActorLocation();
	pos.X += d.X * 10.0;
	pos.Y += d.Y * 20.0;
	pos.X = FMath::Clamp(pos.X, -4000, 4000);
	pos.Y = FMath::Clamp(pos.Y, -4000, 4000);
	this->SetActorLocation(pos);

}

void APlayerPawn::PressedCamAxis(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D v = Value.Get<FVector2D>();

	// Axis Input Value
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("R X:%f Y:%f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// âÒì]
	FRotator rot = this->GetActorRotation();
	rot.Pitch += v.Y;
	rot.Yaw += v.X;
	this->SetActorRotation(rot);
}
