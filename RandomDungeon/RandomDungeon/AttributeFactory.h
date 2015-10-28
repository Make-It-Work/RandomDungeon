#pragma once
#include <string>
class Attribute;

class AttributeFactory
{
public:
	AttributeFactory();
	~AttributeFactory();
	Attribute * createAttribute(std::string attrName);
};

