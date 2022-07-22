// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;//true 代表没帧进行调用

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	InitLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	bGotoInitLocation = false;
	WorldOrigin = FVector(0.0f);
	TicklocationOffset = FVector(0.0f);
	bShowldMove = false;

	InitForce = FVector(0.0f);
	InitTorque = FVector(0.0f);
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation=GetActorLocation();
	if (bGotoInitLocation)
	{
		SetActorLocation(InitLocation);
	}	

	//MyStaticMesh->AddForce(InitForce,"NAME_None",bAccelChange);
	//MyStaticMesh->AddTorqueInDegrees(InitTorque, "NAME_None", bAccelChange);
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShowldMove) 
	{
		FHitResult HitResult;
		AddActorLocalOffset(TicklocationOffset,true,&HitResult);
		UE_LOG(LogTemp, Warning, TEXT("X:%f,Y:%f,Z:&f"), HitResult.Location.X, HitResult.Location.Y,HitResult.Location.Z);
	}
}

