// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CPPArcade/Components/ShootComponent.h"



#include "PlayerPawn.generated.h"


UCLASS()
class CPPARCADE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnTouchMove(ETouchIndex::Type Index, FVector Location);
	void OnTouchPress(ETouchIndex::Type Index, FVector Location);
	APlayerController* PlayerController;
	virtual void PossessedBy(AController* NewController) override;

		FVector2D MoveLimit;
private:
	FVector2D TouchLocation;
	bool Touching;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UBoxComponent* PawnCollision;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components")
		UStaticMeshComponent* PawnMesh;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UCameraComponent* PawnCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controls")
		float TouchMoveSensivity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
		UShootComponent* ShootComponent;
};
