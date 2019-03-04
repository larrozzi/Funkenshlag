#pragma once
#include <string>

enum HouseColor { NO_COLOR, RED, BLUE, GREEN, YELLOW, BLACK, PINK};

class House {
private:
	//color of the house
	HouseColor color;
public:

	//default constructor
	House();
	House(HouseColor color);
	~House();
	inline HouseColor getColor() const;
	inline void setColor(HouseColor color);

};