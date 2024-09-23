#pragma once
#include "MjBaseBody.h"
#include "MjComponent.h"

class UMjBaseJoin:public UMjComponent
{
public:
	UMjBaseJoin();

	void GetConnectedBodies(UMjBaseBody* grandParentBody, UMjBaseBody* parentBody);

	virtual void OnBindToRuntime(const mjModel* m, mjData_* data) override;

	

public:
	UMjBaseBody* ParentBody;
	UMjBaseBody* GrandParentBody;
	int QposAddress =-1;
	int DofAddress=-1;
};
