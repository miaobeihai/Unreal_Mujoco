#include "MjBoxShape.h"

void UMjBoxShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjBoxShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjBoxShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
