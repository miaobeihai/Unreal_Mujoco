#include "MjSphereShape.h"

#include "Components/SphereComponent.h"

UMjSphereShape::UMjSphereShape()
{
	CreateDefaultSubobject<USphereComponent>("Sphere");
}

void UMjSphereShape::ToMjcf(FXmlNode* Mjcf, const FTransform& Transform)
{
	UMjShape::ToMjcf(Mjcf, Transform);
}

void UMjSphereShape::FromMjcf(FXmlNode* Mjcf)
{
	UMjShape::FromMjcf(Mjcf);
}

FQuat UMjSphereShape::GetChangeStamp()
{
	return UMjShape::GetChangeStamp();
}
