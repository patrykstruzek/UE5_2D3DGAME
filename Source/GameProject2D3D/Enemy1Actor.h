// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Enemy1Actor.generated.h"

UCLASS()
class PROJECT2DCURRENT_API AEnemy1Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy1Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class UStaticMeshComponent* AllHandle;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class UPaperFlipbookComponent* Flipbook;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Flipbooks")
	class UPaperFlipbook* IdleAnimation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Flipbooks")
	class UPaperFlipbook* WalkingAnimation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Flipbooks")
	class UPaperFlipbook* HitAnimation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Flipbooks")
	class UPaperFlipbook* DamageTakenAnimation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float DistanceThreshold = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MoveSpeed = 100.f;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	//ACharacter* PlayerCharacter;
	
	//UFUNCTION(BlueprintCallable)
	//void MoveTowardsPlayer(float &DeltaTime);
	
	UFUNCTION(BlueprintCallable)
	void UpdateFlipbookDirection();
	
	bool bIsFacingRight = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
