#include "MjInertial.h"

void UMjInertial::OnParseMjcf(const mjModel* m)
{
	UMjComponent::OnParseMjcf(m);
}

FXmlNode* UMjInertial::OnGenerateMjcf(FXmlFile* Doc)
{
	return UMjComponent::OnGenerateMjcf(Doc);
}
