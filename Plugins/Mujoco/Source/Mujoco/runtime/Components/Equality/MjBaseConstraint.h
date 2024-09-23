#pragma once
#include "MjComponent.h"

class UMjBaseConstraint:public UMjComponent
{
public:
	UMjBaseConstraint();
	
	virtual void ToMjcf(FXmlNode* Mjcf, const FTransform& Transform) PURE_VIRTUAL(UIMjShape::ToMjcf, );
	virtual void FromMjcf(FXmlNode* Mjcf) PURE_VIRTUAL(UIMjShape::FromMjcf, );

	virtual void OnParseMjcf(const mjModel* m) override;

	virtual FXmlNode* OnGenerateMjcf(FXmlFile* Doc) override;

protected:
	FString ConstraintName;

	//todo
	//SolverImpedance SolverImpedanceSettings;
	//SolverReference SolverReferenceSettings;
	
};
