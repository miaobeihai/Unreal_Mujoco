#include "MjBaseJoin.h"

UMjBaseJoin::UMjBaseJoin()
{
	ObjectType=mjtObj_::mjOBJ_JOINT;
	GetConnectedBodies(GrandParentBody, ParentBody);
	if (!ParentBody)
	{
		UE_LOG(LogTemp, Error, TEXT("Parent body not found for joint"));
	}
	
}

void UMjBaseJoin::GetConnectedBodies(UMjBaseBody* grandParentBody, UMjBaseBody* parentBody)
{
	//todo 
}


void UMjBaseJoin::OnBindToRuntime(const mjModel* m, mjData_* data)
{
	QposAddress=m->jnt_qposadr[MujocoId];
	DofAddress=m->jnt_dofadr[MujocoId];
}
