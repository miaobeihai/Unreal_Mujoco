#include "MjFixedTendon.h"

void UMjFixedTendon::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseTendon::ToMjcf(Mjcf, Transform);
}

void UMjFixedTendon::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseTendon::FromMjcf(Mjcf);
}
