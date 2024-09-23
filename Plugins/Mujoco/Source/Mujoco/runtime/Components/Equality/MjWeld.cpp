#include "MjWeld.h"

void UMjWeld::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseConstraint::ToMjcf(Mjcf, Transform);
}

void UMjWeld::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseConstraint::FromMjcf(Mjcf);
}
