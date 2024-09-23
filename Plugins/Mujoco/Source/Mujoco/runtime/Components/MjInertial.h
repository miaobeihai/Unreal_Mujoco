#pragma once
#include "MjComponent.h"

class UMjInertial:public UMjComponent
{
public:
	virtual void OnParseMjcf(const mjModel* m) override;

	virtual FXmlNode* OnGenerateMjcf(FXmlFile* Doc) override;
};
