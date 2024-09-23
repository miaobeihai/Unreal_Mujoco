#include "MjEllipsoidShape.h"

void UMjEllipsoidShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjEllipsoidShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjEllipsoidShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
