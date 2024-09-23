// MjXmlModifiers.h
#pragma once

#include "CoreMinimal.h"
#include "XmlNode.h"
#include "XmlFile.h"



class MUJOCO_API FMjXmlModifiers 
{
	

public:
	FMjXmlModifiers(FXmlFile* XmlFile);

	
	void ApplyModifiersToElement(FXmlNode* element, FString elementName = TEXT(""));

	
	TArray<FXmlNode*> GetDefaultAncestry(FXmlNode* ClassElement, FString NodeType);

	
	TArray<FString> GetApplicableDefaultClasses(FXmlNode* Element);

	
	void CopyAttributes(FXmlNode* From, FXmlNode* To);

	
	void CopyAttributesOverwriteExisting(FXmlNode* From, FXmlNode* To);

private:
	
	FXmlFile* Root;

	// ... other methods and properties ...
};
