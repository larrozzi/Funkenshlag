#pragma once

#include <string>

using std::shared_ptr;

enum HouseColor { NO_COLOR, RED, BLUE, GREEN, YELLOW, BLACK, PINK};

class CityNode;

class House
{
private:
	//color of the house
	HouseColor color;
    int price = 0;
    shared_ptr<CityNode> city;
    
public:

	//default constructor
	House();
	House(HouseColor color);
    House(shared_ptr<CityNode> city, HouseColor color);
	~House();
    
    // getters/setters
	HouseColor getColor() const;
	void setColor(HouseColor color);
    
    int getPrice() const;
    void setPrice(int price);
    
    shared_ptr<CityNode> getCity() const;
    void setCity(shared_ptr<CityNode> city);

	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
    //friend std::istream& operator>>(std::istream& input, House& clr);

};
