#pragma once
#include "MjBody.h"
#include "MjComponent.h"
#include "MjExclude.generated.h"

UCLASS()
class UMjExclude:public UMjComponent
{
	GENERATED_BODY()
public:
	UMjExclude();

	 void OnParseMjcf(const mjModel* m) override;
	 FXmlNode* OnGenerateMjcf(FXmlFile* Doc) override;

public:
	UMjBody *Body1;
	UMjBody *Body2;
};
