// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class CPROJECT2_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor1();

	UPROPERTY(VisibleAnywhere,Category="My Actor Components")
	UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Vector")//只允许在实力上运用
	FVector InitLocation;

	UPROPERTY(VisibleInstanceOnly,Category="My Actor Properties | Vector")
	FVector PlacedLocation;

	UPROPERTY(EditDefaultsOnly,Category="My Actor Properties | Vector") //只能在蓝图控制面板中进行编辑
	bool bGotoInitLocation;

	UPROPERTY(VisibleDefaultsOnly,Category="My Actor Properties | Vector")//只能在蓝图中看不能编辑
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector",meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -10.0f, UIMax = 10.0f))//允许在任何地方进行编辑  ClampMin-ClampMax是点击输入是限制的范围，UIMax-UIMin 是拖动限制的范围
	FVector TicklocationOffset;
	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector")//允许在任何地方进行编辑
	bool bShowldMove;

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	FVector InitForce;//默认的力

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	FVector InitTorque;//默认的力矩

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	bool bAccelChange;//忽略质量
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
