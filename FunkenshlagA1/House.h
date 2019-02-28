#pragma once
#include <string>

class House {
public:
	enum HouseColor { NONE, RED, BLUE, GREEN, YELLOW, BLACK };
	//default constructor
	House();
	House(HouseColor color);
	~House();
	inline HouseColor getColor() const;
	inline void setColor(HouseColor color);
private:
	//color of the house
	HouseColor color;
};