#pragma once
#include "MjShape.h"

class UMjSphereShape:public UMjShape
{
public:
	UMjSphereShape();
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) override;
	virtual void FromMjcf(FXmlNode* Mjcf) override;
	virtual FQuat GetChangeStamp() override;
};
