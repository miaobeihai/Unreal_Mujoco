#include "MjCylinderShape.h"

void UMjCylinderShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjCylinderShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjCylinderShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
