#include "Resource.h"

Resource::Resource(){
	price = 0;
	type = NONE;
}

Resource::Resource(int price, Type type){
	this->price = price;
	this->type = type;

}

inline int Resource::getPrice(){
	return price;
}

void Resource::setPrice(int price){
	this->price = price;
}
