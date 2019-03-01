#pragma once
#include <string>

enum HouseColor { NONE, RED, BLUE, GREEN, YELLOW, BLACK };

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