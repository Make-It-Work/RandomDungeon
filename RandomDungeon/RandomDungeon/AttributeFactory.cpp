#include "stdafx.h"
#include "AttributeFactory.h"
#include "Attribute.h"

AttributeFactory::AttributeFactory()
{
}


AttributeFactory::~AttributeFactory()
{
}

Attribute* AttributeFactory::createAttribute(std::string attrName) {
	Attribute* a = new Attribute();
	a->setName(attrName);
	return a;
}
