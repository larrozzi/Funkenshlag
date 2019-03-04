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
int Resource::getPrice() const {
	return price;
}

void Resource::setPrice(int price) {
	this->price = price;
}

