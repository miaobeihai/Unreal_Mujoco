#include "MjBaseConstraint.h"

UMjBaseConstraint::UMjBaseConstraint()
{
	ObjectType=mjtObj::mjOBJ_EQUALITY;
}

void UMjBaseConstraint::OnParseMjcf(const mjModel* m)
{
	UMjComponent::OnParseMjcf(m);
}

FXmlNode* UMjBaseConstraint::OnGenerateMjcf(FXmlFile* Doc)
{
	return UMjComponent::OnGenerateMjcf(Doc);
}
