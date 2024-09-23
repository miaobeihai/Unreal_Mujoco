#include "MjBaseTendon.h"

UMjBaseTendon::UMjBaseTendon()
{
	ObjectType=mjtObj::mjOBJ_TENDON;
}

void UMjBaseTendon::OnsyncState(mjData_* data)
{
	UMjComponent::OnsyncState(data);
}

void UMjBaseTendon::OnParseMjcf(const mjModel* m)
{
	UMjComponent::OnParseMjcf(m);
}

FXmlNode* UMjBaseTendon::OnGenerateMjcf(FXmlFile* Doc)
{
	return UMjComponent::OnGenerateMjcf(Doc);
}
