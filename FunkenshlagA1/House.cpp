#include "House.h"
#include <string>

House::House() {
	color = NONE;
}

House::House(HouseColor color) {
	this->color = color;
}

House::~House() {

}

inline HouseColor House::getColor() const {
	return color;
}

inline void House::setColor(HouseColor color) {
	this->color = color;
}