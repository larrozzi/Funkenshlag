#pragma once

// included dependencies

//#include "PowerPlantCards.h"
//#include "Resource.h"
//#include "ResourceMarket.h"
//#include "CityNode.h"
#include "House.h"
#include <memory>
#include <vector>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::vector;

//enum HouseColor { Blue, Red, Green, Yellow, Black };

class Player
{

private:
	string name;
	int elektro = 50;
	vector <House> houses;
	HouseColor _color;

public:
	
	
	Player();
	Player(string name,  int electro, HouseColor _color);
	~Player();

	string getName() const;
	void setName(string name);

	int getElektro() const;
	void setElektro(int elektro);

	HouseColor getColor()const;
	inline void setColor( HouseColor _color);

	vector<House>grabhouses();

	//void printHouses();
	//void OutputPlayerStatus() const;


	// overloading output operator
	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& colour);
	friend std::ostream& operator<<(std::ostream& outs, const Player& player);
};

