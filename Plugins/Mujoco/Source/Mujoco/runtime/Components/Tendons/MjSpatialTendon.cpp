#include "MjSpatialTendon.h"

void UMjSpatialTendon::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjBaseTendon::ToMjcf(Mjcf, Transform);
}

void UMjSpatialTendon::FromMjcf(FXmlNode* Mjcf)
{
	UMjBaseTendon::FromMjcf(Mjcf);
}
