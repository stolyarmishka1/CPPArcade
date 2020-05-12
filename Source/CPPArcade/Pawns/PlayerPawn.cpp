// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APlayerPawn::APlayerPawn()
	:
	TouchMoveSensivity(1.f),
	MoveLimit((600, 500))
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PawnCollision"));
	
	RootComponent = PawnCollision;
	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(PawnCollision);


	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	ShootComponent = CreateDefaultSubobject<UShootComponent>(TEXT("ShootComponent"));
	
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
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

	InputComponent->BindTouch(IE_Repeat, this, &APlayerPawn::OnTouchMove);
	InputComponent->BindTouch(IE_Pressed, this, &APlayerPawn::OnTouchPress);

}
void APlayerPawn::OnTouchPress(ETouchIndex::Type Index, FVector Location)
{
	TouchLocation = FVector2D(Location);
}

void APlayerPawn::OnTouchMove(ETouchIndex::Type Index, FVector Location)
{
		

		FVector2D TouchDeltaMove = FVector2D(TouchLocation.X - Location.X, TouchLocation.Y - Location.Y);
		TouchDeltaMove = TouchDeltaMove * TouchMoveSensivity;
		FVector NewLocation = GetActorLocation();
		NewLocation.X = FMath::Clamp(NewLocation.X + TouchDeltaMove.Y, -MoveLimit.Y, MoveLimit.Y);
		NewLocation.Y = FMath::Clamp(NewLocation.Y + TouchDeltaMove.X*-1.f, -MoveLimit.X, MoveLimit.X);

		SetActorLocation(NewLocation);
		TouchLocation = FVector2D(Location);
	
	
	
}


void APlayerPawn::PossessedBy(AController * NewController)
{
	
	//PlayerController = Cast<APlayerController>(NewController);
}
