#include "Resource.h"
#include <iostream>

Resource::Resource() {
	//price of the resource
	price = 0;
	//type of the resource
	type = NONE;
}

Resource::Resource(int price, Type type) {
	this->price = price;
	this->type = type;
}

Type Resource::getType() const {
	return type;
}

void Resource::setType(Type type) {
	this->type = type;
}
inline int Resource::getPrice() const {
	return price;
}

void Resource::setPrice(int price) {
	this->price = price;
}

// method to convert enum Type to string
std::string Resource::printType(Type resource) const
{
	switch (resource) {
	case COAL:		return "COAL";
	case OIL:		return "OIL";
	case HYBRID:	return "HYBRID";
	case GARBAGE:	return "GARBAGE";
	case URANIUM:	return "URANIUM";
	case ECOFUSION: return "ECOFUSION";
	case NONE:		return "NONE";
	}
}

// overloading output stream operator for Resource
std::ostream& operator<<(std::ostream& outs, const Resource& resource)
{
	outs << resource.price << "\t" << resource.printType(resource.type);

	return outs;
}

