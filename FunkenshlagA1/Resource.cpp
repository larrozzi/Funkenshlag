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
// overloading output operator for the enum Type class
std::ostream& operator<<(std::ostream& outs, const Type& resource)
{
	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	switch (resource) {
		PROCESS_VAL(COAL);
		PROCESS_VAL(OIL);
		PROCESS_VAL(HYBRID);
		PROCESS_VAL(GARBAGE);
		PROCESS_VAL(URANIUM);
		PROCESS_VAL(ECOFUSION);
		PROCESS_VAL(NONE);
	}
#undef PROCESS_VAL
	return outs << s;
}


/*
 // OR
 std::ostream& operator<<(std::ostream& outs, const Type& resource)
 {
 switch(resource) {
 case COAL       : outs << "COAL";       break;
 case OIL        : outs << "OIL";        break;
 case HYBRID     : outs << "HYBRID";     break;
 case GARBAGE    : outs << "GARBAGE";    break;
 case URANIUM    : outs << "URANIUM";    break;
 case ECOFUSION  : outs << "ECOFUSION";  break;
 case NONE       : outs << "NONE";       break;
 }
 return outs;
 }
 */

Type stringToType(std::string s) {
	if (s == "COAL") {
		return COAL;
	}
	else if (s == "OIL") {
		return OIL;
	}
	else if (s == "GARBAGE") {
		return GARBAGE;
	}
	else if (s == "URANIUM") {
		return URANIUM;
	}
	return NONE;
}

