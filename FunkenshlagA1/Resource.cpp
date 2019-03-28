#include "Resource.h"
int Resource::coalInStock = 24;
int Resource::oilInStock = 24;
int Resource::garbageInStock = 24;	
int Resource::uraniumInStock = 12;

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

const int Resource::getMAX_COAL() {
	return MAX_COAL;
}

const int Resource::getMAX_OIL() {
	return MAX_OIL;
}

const int Resource::getMAX_GARBAGE() {
	return MAX_GARBAGE;
}

const int Resource::getMAX_URANIUM() {
	return MAX_URANIUM;
}
Type Resource::getType() const {
	return type;
}

int Resource::getCoalInStock() {
	return coalInStock;
}
int Resource::getOilInStock() {
	return oilInStock;
}
int Resource::getGarbageInStock() {
	return garbageInStock;
}
int Resource::getUraniumInStock() {
	return uraniumInStock;
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

void Resource::decreCoalInStock() {
	coalInStock--;
}
void Resource::decreOilInStock() {
	oilInStock--;
}
void Resource::decreGarbageInStock() {
	garbageInStock--;
}
void Resource::decreUraniumInStock() {
	uraniumInStock--;
}

// method to convert enum Type to string
std::string Resource::printType() const
{
	switch (this->type) {
	case COAL:		return "COAL";
	case OIL:		return "OIL";
	case HYBRID:	return "HYBRID";
	case GARBAGE:	return "GARBAGE";
	case URANIUM:	return "URANIUM";
	case ECOFUSION: return "ECOFUSION";
	case NONE:		return "NONE";
	default:        return "ERROR";
	}
}

// overloading output stream operator for Resource
std::ostream& operator<<(std::ostream& outs, const Resource& resource)
{
	outs << "PRICE: "<< resource.price << "\t" << "TYPE: " <<  resource.printType();

	return outs;
}

