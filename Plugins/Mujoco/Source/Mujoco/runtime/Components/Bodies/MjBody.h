#pragma once
#include "MjBaseBody.h"
#include "MjBody.generated.h"

UCLASS()
class UMjBody:public UMjBaseBody
{
	GENERATED_BODY()
public:
	UMjBody();
	void OnParseMjcf(const mjModel* m) override;
	FXmlNode*  OnGenerateMjcf(FXmlFile* Doc) override;
	void OnsyncState(mjData_* data) override;

public:
	float GravityCompensation;
	
};
