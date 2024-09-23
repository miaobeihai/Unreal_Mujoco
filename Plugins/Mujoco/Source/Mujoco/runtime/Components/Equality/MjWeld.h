#pragma once
#include "MjBaseConstraint.h"

class UMjWeld:public UMjBaseConstraint
{
public:
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) override;
	virtual void FromMjcf(FXmlNode* Mjcf) override;
};
