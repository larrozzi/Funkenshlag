#pragma once

// included dependencies

//#include "PowerPlantCards.h"
//#include "Resource.h"
//#include "ResourceMarket.h"
#include "CityNode.h"
#include "House.h"
#include <memory>
#include <vector>
#include <iostream>

using std::shared_ptr;
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

	
	string getName() const;
	void setName(string name);

	int getElektro() const;
	void setElektro(int elektro);

	HouseColor getColor() const;
	void setColor( HouseColor color);

	vector<House>grabhouses();

	bool buildinCity(string city);
	void printOwnedCities();
	//bool  buildinCity(vector <CityNode>& city);

	//bool BuildHouse(CityNode& city, House& house);


	// overloading output operator
	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
	friend std::ostream& operator<<(std::ostream& outs, const Player& player);
};

