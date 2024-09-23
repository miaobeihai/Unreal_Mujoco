// Fill out your copyright notice in the Description page of Project Settings.


#include "MjComponent.h"

#include "XmlFile.h"


// Sets default values for this component's properties
UMjComponent::UMjComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMjComponent::ParseMjcf(const mjModel* m)
{
	OnParseMjcf(m);
}

void UMjComponent::BindToRuntime(const mjModel* m, mjData_* data)
{
	mj_name2id(m, (int)ObjectType, TCHAR_TO_ANSI(*MujocoName));
	if (MujocoId==-1&&!buppressNameAttribute)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to bind %s to runtime"), *MujocoName);
	}
	else
	{
		OnBindToRuntime(m, data);
	}
}

void UMjComponent::OnApplicationQuit()
{
}

void UMjComponent::OnDisable()
{
}

void UMjComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Update();
}

void UMjComponent::BeginPlay()
{
	OnEnable();
}

void UMjComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnDisable();
}

void UMjComponent::OnEnable()
{
}

void UMjComponent::Update()
{
	//todo  scene
}

FXmlNode* UMjComponent::GenerateMjcf(FString Name, FXmlFile* Doc)
{
	MujocoName = Name;

	FXmlNode* Mjcf = OnGenerateMjcf(Doc);
	if (!bSuppressNameAttribute) {
		//Mjcf->SetAttribute("name", Name);
	}

	return Mjcf;
}

