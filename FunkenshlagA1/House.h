#pragma once
#include <string>

class House {
private:
	std::string color;
public:
	House();
	House(std::string color);
	std::string getColor();
	~House();
};
