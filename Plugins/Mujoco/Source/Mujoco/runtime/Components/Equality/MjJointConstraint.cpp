#include "MjJointConstraint.h"

void UMjJointConstraint::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseConstraint::ToMjcf(Mjcf, Transform);
}

void UMjJointConstraint::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseConstraint::FromMjcf(Mjcf);
}
