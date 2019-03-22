//  COMP345A1
//
//  Created by Yassine Laaroussi 2019-02-08.
//  Updated 2019-03-06
//

#pragma once

// included dependencies
#include "House.h"
#include "PowerPlantCards.h"
#include "PPmarket.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;
using std::shared_ptr;

class Player
{

private:
	string name;
	int elektro = 50;
	vector <House> houses;
	//vector <CityNode> mycities;  
	vector <string> mycities;
	vector <string> mapcities;
	vector<shared_ptr<PowerPlantCards>> myPowerPlants;
	HouseColor color;
	int mybid;
	int static highestBid;

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

	//method to read cities from map file
	void readFile();

	// method to build own a city
	bool buildinCity(string city);

	// method to print owned cities
	void printOwnedCities();

	//buypowerplant
	bool buyPowerPlant(PPmarket&, int ,int);

	bool AddPowerPlant(shared_ptr<PowerPlantCards> powerplant);
	
	bool Auction(const PPmarket& ppMarket, int position, int mybid);

	bool Pass();
	
	/*void ReplacePowerPlant(<shared_ptr<PowerPlant>>, int);
	
	int getHighestPowerPlant();*/

	// overloading output operator
	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
	friend std::ostream& operator<<(std::ostream& outs, const Player& player);
};

