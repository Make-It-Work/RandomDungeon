#include "stdafx.h"
#include "Attribute.h"


Attribute::Attribute()
{
}


Attribute::~Attribute()
{
}

void Attribute::setName(std::string name) {
	_name = name;
}

std::string Attribute::getName() {
	return _name;
}
