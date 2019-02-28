#include "Resource.h"

Resource::Resource(){
	//price of the resource
	price = 0;
	//type of the resource
	type = NONE;
}

Resource::Resource(int price, Type type){
	this->price = price;
	this->type = type;

}

inline Resource::Type Resource::getType() const {
	return type;
}

inline void Resource::setType(Resource::Type type) {
	this->type = type;
}
inline int Resource::getPrice() const{
	return price;
}

inline void Resource::setPrice(int price){
	this->price = price;
}
