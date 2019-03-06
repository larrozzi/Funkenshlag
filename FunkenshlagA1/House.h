#pragma once
#include <string>

enum HouseColor { NO_COLOR, RED, BLUE, GREEN, YELLOW, BLACK, PINK};

static HouseColor convert(const std::string& clr)
{
	if (clr == "NO_COLOR") return NO_COLOR;
	else if (clr == "RED") return RED;
	else if (clr == "BLUE") return BLUE;
	else if (clr == "GREEN") return GREEN;
	else if (clr == "YELLOW") return YELLOW;
	else if (clr == "BLACK") return BLACK;
	else if (clr == "PINK") return PINK;
	else return NO_COLOR;
}
class House {
private:
	//color of the house
	HouseColor color;
public:

	//default constructor
	House();
	House(HouseColor color);
	~House();
	HouseColor getColor() const;
	void setColor(HouseColor color);

	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
};