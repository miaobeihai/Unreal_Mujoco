#pragma once
#include "MjBaseTendon.h"

class UMjSpatialTendon:public UMjBaseTendon
{
public:
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) override;
	virtual void FromMjcf(FXmlNode* Mjcf) override;
};
