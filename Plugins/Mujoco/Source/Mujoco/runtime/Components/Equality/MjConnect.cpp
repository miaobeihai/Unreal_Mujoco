#include "MjConnect.h"

UMjConnect::UMjConnect()
{
		ConstraintName=TEXT("connect");
}

void UMjConnect::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseConstraint::ToMjcf(Mjcf, Transform);
}

void UMjConnect::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseConstraint::FromMjcf(Mjcf);
}
