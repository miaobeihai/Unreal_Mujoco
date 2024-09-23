#pragma once
#include "MjBaseBody.h"
#include "MjMocapBody.generated.h"

UCLASS()
class UMjMocapBody:public UMjBaseBody
{
	GENERATED_BODY()
public:
	UMjMocapBody();
	void OnParseMjcf(const mjModel* m) override;
	FXmlNode* OnGenerateMjcf(FXmlFile* Doc) override;
	void OnsyncState(mjData_* data) override;
};
