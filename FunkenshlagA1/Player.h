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


class Player
{

public:
	enum HouseColor { Blue, Red, Green, Yellow, Black };
	
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
	void OutputPlayerStatus() const;

	//bool BuildHouse(CityNode& city, House& house);
	//vector <PowerPlantCards> getPowerplant();
	//vector <Resource> getRecources();

	
	//bool bidonPowerPlant(cardDeck& cardDeck, int position, int price);

	//bool AddPowerPlant(PowerPlantCards powerplant);
	//void ReplacePowerPlant(PowerPlantCards, int);
	//int getHighestPowerPlant();

	//auto_ptr<HouseColor> const& getColor() const;

	//bool BuyResources(ResourceMarket&, PowerPlantCards&, Resource, int);
	
	
	//bool BuildHouse(CityNode& city, auto_ptr <House> house);
	
 private:
	string name;
	int elektro = 50;
	vector <House> houses;
	HouseColor _color;
	//	vector<Resource> resources;
		//HouseColor color;
		//vector<PowerPlantCards> myPowerPlants;

};

//inline std::ostream& operator <<(std::ostream& stream, const Player& player);