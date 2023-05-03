// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "GameFramework/Character.h"
#include "MainActor.generated.h"


UCLASS()
class PROJECT2DCURRENT_API AMainActor : public ACharacter
{
	GENERATED_BODY()

public:

	AMainActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")

	class UStaticMeshComponent* AllHandle = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* CameraHandle = nullptr;

	TObjectPtr<UStaticMeshComponent> AllHandle = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> CameraHandle = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCapsuleComponent> CharacterCapsule = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	TObjectPtr<UPaperFlipbookComponent> Flipbook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sprites")
	TObjectPtr<UPaperFlipbook> Idle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sprites")
	TObjectPtr<UPaperFlipbook> Walking = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sprites")
	TObjectPtr<UPaperFlipbook> Slash = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> JumpAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	TObjectPtr<UInputAction> SlashAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")

	class UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	class UInputMappingContext* MappingContext;

	TObjectPtr<UInputMappingContext> MappingContext = nullptr;

	UFUNCTION(BlueprintCallable)
	void SetMappingContext();
	
	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void SetMappingContext();
	
	UFUNCTION(BlueprintCallable)
	void Dash(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void OnDashCooldownExpired();
		
	UFUNCTION(BlueprintCallable)
	void UpdateFlipbookDirection();

	UFUNCTION(BlueprintCallable)
	void PlayAnimation();
	
	UFUNCTION(BlueprintCallable)
	void PlaySlash();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	bool bIsFacingRight = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dash")
	float DashImpulseStrength = 5000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dash")
	float DashCooldownTime = 1.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dash")
	bool bCanDash = true;

	FTimerHandle DashCooldownTimerHandle;


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
