#include "MjTendonConstraint.h"

void UMjTendonConstraint::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseConstraint::ToMjcf(Mjcf, Transform);
}

void UMjTendonConstraint::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseConstraint::FromMjcf(Mjcf);
}
