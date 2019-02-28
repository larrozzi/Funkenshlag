#include "House.h"
#include <string>

House::House() {
	color = NONE;
}

House::House(House::HouseColor color) {
	this->color = color;
}

House::~House() {

}

inline House::HouseColor House::getColor() const {
	return color;
}

inline void House::setColor(House::HouseColor color) {
	this->color = color;
}