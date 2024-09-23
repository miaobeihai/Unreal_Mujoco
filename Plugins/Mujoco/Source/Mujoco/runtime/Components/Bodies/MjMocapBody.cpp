#include "MjMocapBody.h"

UMjMocapBody::UMjMocapBody()
{
}

void UMjMocapBody::OnParseMjcf(const mjModel* m)
{
	UMjBaseBody::OnParseMjcf(m);
}

FXmlNode* UMjMocapBody::OnGenerateMjcf(FXmlFile* Doc)
{
	return UMjBaseBody::OnGenerateMjcf(Doc);
}

void UMjMocapBody::OnsyncState(mjData_* data)
{
	UMjBaseBody::OnsyncState(data);
}
