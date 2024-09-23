// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MjComponent.h"
#include "Components/ActorComponent.h"
#include "MjScene.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUJOCO_API UMjScene : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMjScene();

	static UMjScene* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = NewObject<UMjScene>();
		}
		return Instance;
	}


private:
	static UMjScene* Instance ;
};
