#pragma once
#include "MjComponent.h"

class UMjBaseTendon:public UMjComponent
{
public:
	UMjBaseTendon();

	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) PURE_VIRTUAL(UIMjShape::ToMjcf, );
	virtual void FromMjcf(FXmlNode* Mjcf) PURE_VIRTUAL(UIMjShape::FromMjcf, );

public:
	virtual void OnsyncState(mjData_* data) override;
	virtual void OnParseMjcf(const mjModel* m) override;
	virtual  FXmlNode* OnGenerateMjcf(FXmlFile* Doc) override;
public:
	//todo 
	//SolverSettings Solver;

	float SpringLength= -1.0f;
	float Stiffness =0.0f ;
	float Damping =0.0f;

	//Tendon length
	float Length;
	
};
		