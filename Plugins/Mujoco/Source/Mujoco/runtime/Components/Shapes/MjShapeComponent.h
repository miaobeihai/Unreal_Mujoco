#pragma once

#include "MjComponent.h"

class UMjPlaneShape;
class UMjBoxShape;
class UMjEllipsoidShape;
class UMjCylinderShape;
class UMjCapsuleShape;
class UMjSphereShape;

enum EShapeTypes
{
	Sphere,
	Capsule,
	Ellipsoid,
	Cylinder,
	Box,
	Plane,
	Mesh
};
class UMjShapeComponent:public UMjComponent
{
public:


public:
	EShapeTypes ShapeType;
	UMjSphereShape *Sphere;
	UMjCapsuleShape *Capsule;
	UMjCylinderShape *Cylinder;
	UMjEllipsoidShape *Ellipsoid;
	UMjBoxShape* Box;
	UMjPlaneShape* Plane;
	//TODO  Mesh shape 
	
	
};
