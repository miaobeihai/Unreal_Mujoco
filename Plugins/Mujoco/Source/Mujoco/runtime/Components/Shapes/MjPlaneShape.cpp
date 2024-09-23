#include "MjPlaneShape.h"

void UMjPlaneShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjPlaneShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjPlaneShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
