#include "MjCapsuleShape.h"

void UMjCapsuleShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjCapsuleShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjCapsuleShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
