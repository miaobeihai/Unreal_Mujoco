#include "MjBody.h"

UMjBody::UMjBody()
{
}

void UMjBody::OnParseMjcf(const mjModel* m)
{
	UMjBaseBody::OnParseMjcf(m);
}

FXmlNode* UMjBody::OnGenerateMjcf(FXmlFile* Doc)
{
	return nullptr;
}

void UMjBody::OnsyncState(mjData_* data)
{
	UMjBaseBody::OnsyncState(data);
}
