#include "MjExclude.h"

UMjExclude::UMjExclude()
{
	ObjectType=mjtObj::mjOBJ_EXCLUDE;
}

void UMjExclude::OnParseMjcf(const mjModel* m)
{
	UMjComponent::OnParseMjcf(m);
}

FXmlNode* UMjExclude::OnGenerateMjcf(FXmlFile* Doc)
{
	return nullptr;
}
