
#include "House.h"
#include <string>
#include <iostream>

House::House() {
	color = NO_COLOR;
}

House::House(HouseColor color) {
	this->color = color;
}

House::~House() {

}

HouseColor House::getColor() const {
	return color;
}

void House::setColor(HouseColor color) {
	this->color = color;
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

static HouseColor convert(const std::string& clr)
{
	if (clr == "NO_COLOR")		return NO_COLOR;
	else if (clr == "RED")		return RED;
	else if (clr == "BLUE")		return BLUE;
	else if (clr == "GREEN")	return GREEN;
	else if (clr == "YELLOW")	return YELLOW;
	else if (clr == "BLACK")	return BLACK;
	else if (clr == "PINK")		return PINK;
	else return NO_COLOR;
}
