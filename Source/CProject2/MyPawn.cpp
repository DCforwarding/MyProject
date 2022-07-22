// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include"UObject/ConstructorHelpers.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	MyStaticMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshAsset(TEXT("MaterialInstanceConstant'/Engine/BasicShapes/M_Cube_WorldGridMaterial_8D67460644F5AEE976EC80B26230FFEB.M_M_Cube_WorldGridMaterial_8D67460644F5AEE976EC80B26230FFEB'"));   //���ȼ����ļ���
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));   //���ȼ����ļ���
	if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded())
	{
		MyStaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		MyStaticMesh->SetMaterial(0, MaterialAsset.Object);
		MyStaticMesh->SetWorldScale3D(FVector(0.5f));
	}

	//MySpringArm = CreateDefaultSubobject<USpringArmComponent> StaticMeshAsset(TEXT("MySpringArm"));
	MySpringArm = CreateDefaultSubobject<USpringArmComponent> (TEXT("MySpringArm"));
	//MySpringArm->SetupAttachment(GetStaticMeshComponent());
	MySpringArm->SetupAttachment(MyStaticMesh);
	MySpringArm->SetRelativeRotation ( FRotator(-45.0f, 0.0f, 0.0f));
	MySpringArm->TargetArmLength = 400.0f;
	MySpringArm->bEnableCameraLag = true;
	MySpringArm->CameraLagSpeed = 3.0f;

	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	//MyCamera->SetupAttachment(GetSpringArmComponent());
	MyCamera->SetupAttachment(MySpringArm);

	MyCamera->SetRelativeLocation(FVector(-300.0f, 0.0f, 300.0f));
	MyCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	MaxSpeed = 100.0f;
	Velocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(Velocity * DeltaTime, true);//����trueʱ�����Զ�������������������ײ
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);
}

void AMyPawn::MoveForward(float Value) 
{
	Velocity.X = FMath::Clamp(Value, -1.0f, 1.0f) * MaxSpeed;//Clamp����ȡ����ֵ��ֻ�����������仯
}

void AMyPawn::MoveRight(float Value)
{
	Velocity.Y = FMath::Clamp(Value, -1.0f, 1.0f) * MaxSpeed;
}

