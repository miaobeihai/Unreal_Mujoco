#pragma once
#include "MjShape.h"

class UMjPlaneShape:public UMjShape
{
public:
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) override;
	virtual void FromMjcf(FXmlNode* Mjcf) override;
	virtual FQuat GetChangeStamp() override;
};
