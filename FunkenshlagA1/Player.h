//  COMP345A1
//
//  Created by Yassine Laaroussi 2019-02-08.
//  Updated 2019-03-05
//

#pragma once

// included dependencies

#include "CityNode.h"
#include "House.h"
#include <memory>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Player
{

private:
	string name;
	int elektro = 50;
	vector <House> houses;
	//vector <CityNode> mycities;  
	vector <string> mycities;
	HouseColor color;

public:

	Player();
	Player(string name,  int electro, HouseColor color);
	~Player();

	// setters
	void setName(string name);
	void setElektro(int elektro);
	void setColor(HouseColor color);
	// getters
	string getName() const;
	int getElektro() const;
	HouseColor getColor() const;

	// method to create the grab 22 houses from board
	vector<House>grabhouses();

	// method to build own a city
	bool buildinCity(string city);

	// method to print owned cities
	void printOwnedCities();

	// overloading output operator
	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
	friend std::ostream& operator<<(std::ostream& outs, const Player& player);
};

