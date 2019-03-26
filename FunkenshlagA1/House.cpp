
#include "House.h"
#include <string>
#include <iostream>

House::House() {
	color = NO_COLOR;
}

House::House(HouseColor color) {
	this->color = color;
}

House::House(std::shared_ptr<CityNode> city, HouseColor color) : city(city), color(color)
{
    price = city->getHousePrice();
}

House::~House() {}

HouseColor House::getColor() const {
	return color;
}

void House::setColor(HouseColor color) {
	this->color = color;
}

int House::getPrice() const {
    return price;
}

void House::setPrice(int price) {
    this->price = price;
}

std::shared_ptr<CityNode> House::getCity() const {
    return city;
}

void House::setCity(std::shared_ptr<CityNode> city) {
    this->city = city;
}

// overloading output operator for the enum HouseColor
std::ostream& operator<<(std::ostream& outs, const HouseColor& color) {
	const char* c = 0;
#define PROCESS_VAL(p) case(p): c = #p; break;
	switch (color) {
		PROCESS_VAL(NO_COLOR);
		PROCESS_VAL(RED);
		PROCESS_VAL(BLUE);
		PROCESS_VAL(GREEN);
		PROCESS_VAL(YELLOW);
		PROCESS_VAL(BLACK);
		PROCESS_VAL(PINK);
	}
#undef PROCESS_VAL
	return outs << c;
}
