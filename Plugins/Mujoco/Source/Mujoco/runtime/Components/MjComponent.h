// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "mjmodel.h"
#include "mjdata.h"
#include  "mujoco.h"
#include "XmlFile.h"
#include "XmlNode.h"
#include "MjComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUJOCO_API UMjComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMjComponent();

	void ParseMjcf(const mjModel* m);
	 
	void BindToRuntime(const mjModel* m, mjData_* data);

	 virtual void OnBindToRuntime(const mjModel* m, mjData_* data) {}

	 virtual void OnParseMjcf(const mjModel* m) {};

	 virtual  void OnsyncState( mjData_* data) {}

	 void OnApplicationQuit();

	 void OnDisable();

	 void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	 void BeginPlay() override;

	 void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void OnEnable();

	void Update();
	
	virtual FXmlNode* OnGenerateMjcf(FXmlFile* Doc){ return nullptr;}
	
	FXmlNode* GenerateMjcf(FString Name, FXmlFile* Doc);
	
public:
	mjtObj_ ObjectType;
	
protected:
	UPROPERTY()
	FString MujocoName;

	UPROPERTY()
	int32 MujocoId;

	UPROPERTY()
	bool bSuppressNameAttribute;

	

	// Some components (Inertial frames for example) cannot have the name attribute
	// added to the generated Mjcf.
	 bool buppressNameAttribute = false;

	bool bSceneExcludesMe = false;

	bool bExiting = false;
	
};
