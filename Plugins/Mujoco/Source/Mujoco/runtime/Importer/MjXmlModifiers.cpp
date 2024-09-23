// MjXmlModifiers.cpp
#include "MjXmlModifiers.h"




FMjXmlModifiers::FMjXmlModifiers(FXmlFile* XmlFile)
{
	// Initialize properties
	// ... other initializations ...
	Root=XmlFile;
}

void FMjXmlModifiers::ApplyModifiersToElement(FXmlNode* Element, FString ElementName)
{
	if (ElementName.IsEmpty())
	{
		ElementName = Element->GetTag();
	}
	const FString XmlfileName=TEXT("aggregate");
	FXmlFile* AggregateXmlFile=new FXmlFile(XmlfileName);
	// Combine all defaults into one. At this stage, we want to overwrite attributes defined by
	// the previous defaults.
	FXmlNode* AggregateDefaults =AggregateXmlFile->GetRootNode();
	//AggregateDefaults-("aggregate");

	// Root default leaf should be processed only once, and handled first (so it's overriden).
	FXmlNode* RootDefaultLeaf = Root->GetRootNode()->FindChildNode(ElementName);
	if (RootDefaultLeaf != nullptr)
	{
		CopyAttributes(RootDefaultLeaf, AggregateDefaults);
	}

	// Order matters - reverse class list so that most relevant is last.
	TArray<FString> Classes = GetApplicableDefaultClasses(Element);
	Algo::Reverse(Classes);
	for (FString ClassName : Classes)
	{
		FXmlNode* DefaultClassElement = Root->GetRootNode()->FindChildNode("default");
		if (DefaultClassElement != nullptr && DefaultClassElement->GetAttribute("class") == ClassName)
		{
			// Ancestry iterates up in the tree, but we want to apply changes from remote to specific.
			TArray<FXmlNode*> Ancestors = GetDefaultAncestry(DefaultClassElement, ElementName);
			Algo::Reverse(Ancestors);
			for (FXmlNode* DefaultAncestor : Ancestors)
			{
				CopyAttributesOverwriteExisting(DefaultAncestor, AggregateDefaults);
			}
		}
	}

	// Add the merged attribiutes to the node, without overwriting the existing values.
	CopyAttributes(AggregateDefaults, Element);
}

TArray<FXmlNode*> FMjXmlModifiers::GetDefaultAncestry(FXmlNode* ClassElement, FString NodeType)
{
	TArray<FXmlNode*> Ancestry;
	FXmlNode* DefaultElement = ClassElement;
	FXmlNode* Top = Root->GetRootNode()->FindChildNode("default");

	while (DefaultElement != Top)
	{
		for (const auto& Element : DefaultElement->GetChildrenNodes())
		{
			if (Element->GetTag() == NodeType)
			{
				Ancestry.Add(Element);
			}
		}
		//DefaultElement = DefaultElement->GetParentNode();
	}

	return Ancestry;
}

TArray<FString> FMjXmlModifiers::GetApplicableDefaultClasses(FXmlNode* Element)
{
	TArray<FString> Classes;
	FXmlNode* CurrentElement = Element;
	while (CurrentElement != nullptr)
	{
		FString Class = CurrentElement->GetAttribute("class");
		if (!Class.IsEmpty())
		{
			Classes.Add(Class);
		}
		//to do:
		//CurrentElement = CurrentElement->GetParentNode();
	}

	return Classes;
}
void FMjXmlModifiers::CopyAttributes(FXmlNode* From, FXmlNode* To)
{
	for (const auto& Attribute : From->GetAttributes())
	{
		if (To->GetAttribute(Attribute.GetTag()).IsEmpty())
		{
			// Unreal Engine 4 does not provide a method to set an attribute on an FXmlNode.
			// You would need to implement this functionality yourself.
			//SetAttribute(To, Attribute.GetTag(), Attribute.GetValue());
		}
	}
}

void FMjXmlModifiers::CopyAttributesOverwriteExisting(FXmlNode* From, FXmlNode* To)
{
	for (const auto& Attribute : From->GetAttributes())
	{
		// Unreal Engine 4 does not provide a method to set an attribute on an FXmlNode.
		// You would need to implement this functionality yourself.
		//SetAttribute(To, Attribute.GetTag(), Attribute.GetValue());
	}
}
// ... other method implementations ...