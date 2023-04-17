// Fill out your copyright notice in the Description page of Project Settings.


#include "MainActor.h"
<<<<<<< HEAD
#include "MainCharacter.h"
=======
>>>>>>> e36d8d907f614132a2f3ab55b3e8c52876dcc8dd
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"

<<<<<<< HEAD
// Sets default values
=======
>>>>>>> e36d8d907f614132a2f3ab55b3e8c52876dcc8dd
AMainActor::AMainActor()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	AllHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AllHandle"));
	RootComponent = AllHandle;

	GetCapsuleComponent()->InitCapsuleSize(17.0, 42.0);
	GetCapsuleComponent()->SetupAttachment(AllHandle);

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Flipbook->SetupAttachment(GetCapsuleComponent());
<<<<<<< HEAD
	Flipbook->SetRelativeLocation(FVector(7.0f, 0.0f, -20.0f));

=======
	Flipbook->SetRelativeLocation(FVector(7.0f,0.0f,-20.0f));
	
>>>>>>> e36d8d907f614132a2f3ab55b3e8c52876dcc8dd
	CameraHandle = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraHandle"));
	CameraHandle->SetupAttachment(GetCapsuleComponent());
	CameraHandle->SetRelativeRotation(FRotator(-30.0f, -90.0f, 0.0f));
	CameraHandle->TargetArmLength = 350.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraHandle, USpringArmComponent::SocketName);

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 1.0f;
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 0.0f;
}

void AMainActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocationAndRotation(FVector(0.0f, 0.0f, 100.0f), FRotator(0.0f, -90.0f, 0.0f));

	SetMappingContext();
}

void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateFlipbookDirection();

	PlayAnimation();
}

void AMainActor::SetMappingContext()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem
			= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

<<<<<<< HEAD
void AMainActor::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMainActor::Dash(const FInputActionValue& Value)
{
	if (bCanDash)
	{
		// Disable dashing until dash cooldown has expired
		bCanDash = false;
		GetWorldTimerManager().SetTimer(DashCooldownTimerHandle, this, &AMainActor::OnDashCooldownExpired, DashCooldownTime, false);

		FVector2D MovementVector = Value.Get<FVector2D>();

		if (Controller != nullptr)
		{
			FVector MovementDirection = GetVelocity();
			MovementDirection.X = 0;
			MovementDirection.Normalize();

			// Apply dash impulse to the character
			FVector DashImpulse = MovementDirection * DashImpulseStrength;
			GetCharacterMovement()->AddImpulse(DashImpulse, true);
		}
	}
}

void AMainActor::OnDashCooldownExpired()
{
	bCanDash = true;
}

void AMainActor::UpdateFlipbookDirection()
{
	const FVector MovementDirection = GetVelocity().GetSafeNormal2D();

	// Calculate the dot product between the movement direction and the character's forward direction
	const float DotProduct = FVector::DotProduct(GetActorForwardVector(), MovementDirection);

	// Check if the character is moving in the opposite direction of their current facing
	if ((DotProduct < 0.0f && bIsFacingRight) || (DotProduct > 0.0f && !bIsFacingRight))
	{
		// Flip the flipbook's X axis
		const FRotator SpriteRotation = Flipbook->GetRelativeRotation();
		Flipbook->SetRelativeRotation(FRotator(SpriteRotation.Pitch, SpriteRotation.Yaw + 180.0f, SpriteRotation.Roll));

		// Update the facing direction
		bIsFacingRight = !bIsFacingRight;
	}
}

void AMainActor::PlayAnimation()
{
	FVector v = GetVelocity();

	if (v.Size() == 0.0f)
	{
		Flipbook->Stop();
		Flipbook->Play();
		Flipbook->SetFlipbook(Idle);
	}
	else if (GetMovementComponent()->IsFalling())
	{
		Flipbook->Stop();
	}
	else
	{
		Flipbook->Play();
		Flipbook->SetFlipbook(Walking);
	}
}

void AMainActor::PlaySlash()
{
	Flipbook->Stop();
	Flipbook->SetLooping(false);
	Flipbook->SetFlipbook(Slash);
	Flipbook->Play();
	Flipbook->SetLooping(true);
	Flipbook->SetFlipbook(Idle);
}

=======
// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();

	SetMappingContext();
	
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateFlipbookDirection();

	PlayAnimation();

}

// Called to bind functionality to input
>>>>>>> e36d8d907f614132a2f3ab55b3e8c52876dcc8dd
void AMainActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainActor::Move);
		Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		Input->BindAction(SlashAction, ETriggerEvent::Triggered, this, &AMainActor::PlaySlash);
		Input->BindAction(DashAction, ETriggerEvent::Triggered, this, &AMainActor::Dash);
	}
}

void AMainActor::SetMappingContext()
{
	SetActorLocationAndRotation(FVector(0.0f,0.0f,100.0f),FRotator(0.0f,-90.0f,0.0f));

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void AMainActor::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		AddMovementInput(RightDirection, MovementVector.X);
		
	}
}

void AMainActor::PlayAnimation()
{
	FVector v = GetVelocity();

	if(v.Size() == 0.0f)
	{
		Flipbook->Stop();
		Flipbook->Play();
		Flipbook->SetFlipbook(Idle);
	}
	else if (GetMovementComponent()->IsFalling())
	{
		Flipbook->Stop();
	}
	else
	{
		Flipbook->Play();
		Flipbook->SetFlipbook(Walking);
	}
}

void AMainActor::UpdateFlipbookDirection()
{
	const FVector MovementDirection = GetVelocity().GetSafeNormal2D();

	// Calculate the dot product between the movement direction and the character's forward direction
	const float DotProduct = FVector::DotProduct(GetActorForwardVector(), MovementDirection);

	// Check if the character is moving in the opposite direction of their current facing
	if ((DotProduct < 0.0f && bIsFacingRight) || (DotProduct > 0.0f && !bIsFacingRight))
	{
		// Flip the flipbook's X axis
		const FRotator SpriteRotation = Flipbook->GetRelativeRotation();
		Flipbook->SetRelativeRotation(FRotator(SpriteRotation.Pitch, SpriteRotation.Yaw + 180.0f, SpriteRotation.Roll));

		// Update the facing direction
		bIsFacingRight = !bIsFacingRight;
	}
}

void AMainActor::PlaySlash()
{
	Flipbook->Stop();
	Flipbook->SetLooping(false);
	Flipbook->SetFlipbook(Slash);
	Flipbook->Play();
	Flipbook->SetLooping(true);
	Flipbook->SetFlipbook(Idle);
}