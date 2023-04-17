// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy1Actor.h"
#include "NavigationSystemTypes.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AEnemy1Actor::AEnemy1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AllHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AllHandle"));
	RootComponent = AllHandle;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(AllHandle);
	Capsule->InitCapsuleSize(13.553978, 29.820297);

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	Flipbook->SetupAttachment(AllHandle);
	Flipbook->SetRelativeLocation(FVector(1.0f,0.0f,22.0f));
	Flipbook->SetFlipbook(IdleAnimation);

	//PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
}

// Called when the game starts or when spawned
void AEnemy1Actor::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AEnemy1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateFlipbookDirection();
//	MoveTowardsPlayer(DeltaTime);
}

void AEnemy1Actor::UpdateFlipbookDirection()
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

// void AEnemy1Actor::MoveTowardsPlayer(float& DeltaTime)
// {
// 	if(PlayerCharacter == nullptr)
// 	{
// 		
// 	}
// 	FVector PlayerLocation = PlayerCharacter->GetActorLocation();
//
// 	// Calculate the direction to the player character
// 	FVector Direction = PlayerLocation - GetActorLocation();
// 	Direction.Normalize();
//
// 	// Move towards the player character if close enough
// 	float Distance = FVector::Distance(PlayerLocation, GetActorLocation());
// 	if (Distance <= DistanceThreshold)
// 	{
// 		FVector Movement = Direction * MoveSpeed * DeltaTime;
// 		AddActorWorldOffset(Movement, true);
// 	}
// }






