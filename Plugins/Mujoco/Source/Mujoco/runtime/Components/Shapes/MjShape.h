// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MjShape.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUJOCO_API UMjShape : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMjShape();
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) PURE_VIRTUAL(UIMjShape::ToMjcf, );
	virtual void FromMjcf(FXmlNode* Mjcf) PURE_VIRTUAL(UIMjShape::FromMjcf, );

	
	// Generate a timestamp that can be used to quickly compare if the settings of a shape
	// have changed.
	virtual FQuat GetChangeStamp() PURE_VIRTUAL(UIMjShape::GetChangeStamp, return FQuat(); );

	//    // Draw a debug gizmo for the shape.
	//virtual void DebugDraw(const FTransform& Transform) PURE_VIRTUAL(UIMjShape::DebugDraw, );

};
