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

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Vector")//ֻ������ʵ��������
	FVector InitLocation;

	UPROPERTY(VisibleInstanceOnly,Category="My Actor Properties | Vector")
	FVector PlacedLocation;

	UPROPERTY(EditDefaultsOnly,Category="My Actor Properties | Vector") //ֻ������ͼ��������н��б༭
	bool bGotoInitLocation;

	UPROPERTY(VisibleDefaultsOnly,Category="My Actor Properties | Vector")//ֻ������ͼ�п����ܱ༭
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector",meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -10.0f, UIMax = 10.0f))//�������κεط����б༭  ClampMin-ClampMax�ǵ�����������Ƶķ�Χ��UIMax-UIMin ���϶����Ƶķ�Χ
	FVector TicklocationOffset;
	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector")//�������κεط����б༭
	bool bShowldMove;

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	FVector InitForce;//Ĭ�ϵ���

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	FVector InitTorque;//Ĭ�ϵ�����

	UPROPERTY(EditInstanceOnly,Category="My Actor Properties | Physics")
	bool bAccelChange;//��������
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
