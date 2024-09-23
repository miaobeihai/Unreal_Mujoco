#pragma once
#include "MjBaseConstraint.h"

class UMjConnect:public UMjBaseConstraint
{
public:
	UMjConnect();
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) override;
	virtual void FromMjcf(FXmlNode* Mjcf) override;
};
