//  COMP345A1
//
//  Created by Yassine Laaroussi 2019-02-08.
//  Updated 2019-03-06
//

#pragma once

// included dependencies
#include "House.h"
#include "PowerPlantCards.h"
#include "PPMarketSingleton.h"
//#include "PPmarket.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include "ResourceMarket.h"
#include "PlayerBehaviour.h"

using std::string;
using std::vector;
using std::shared_ptr;

class Player : public Subject
{
private:
    PlayerBehaviour* playB;
    string name;
    int elektro = 50;
    vector<House> houses;
    //vector <CityNode> mycities;
    vector <string> mycities;
    vector <string> mapcities;
    vector<shared_ptr<PowerPlantCards>> myPowerPlants;
    HouseColor color;
    int mybid;
	vector<House>ownedHouses;
	int coalCapacity;
	int oilCapacity;
	int garbageCapacity;
	int uraniumCapacity;
	int coalHeld;
	int oilHeld;
	int garbageHeld;
	int uraniumHeld;

public:
    Player();
    Player(string name, int electro, HouseColor color);
    ~Player();

    // setters
    void setName(string name);
    void setElektro(int elektro);
    void setColor(HouseColor color);
    // getters
    string getName() const;
    int getElektro() const;
    HouseColor getColor() const;
    vector <string> getBuiltHouses() const;
	vector<House>getOwnedHouses();
	int getCoalCapacity() const;
	int getOilCapacity() const;
	int getGarbageCapacity() const;
	int getUraniumCapacity() const;
	int getCoalHeld() const;
	int getOilHeld() const;
	int getGarbageHeld() const;
	int getUraniumHeld() const;

    // method to create the grab 22 houses from board
    vector<House>grabhouses();

    // method to buy house
    bool buyHouse(shared_ptr<House> house);

    //method to read cities from map file
    void readFile();

    // method to build own a city
    bool buildinCity(string city);

    // method to print owned cities
    void printOwnedCities();

    //buypowerplant
    bool buyPowerPlant(PPMarketSingleton&, int ,int);

	void buyResource(Type,ResourceMarket*);

    bool OwnPowerPlant(shared_ptr<PowerPlantCards> powerplant);
    
    bool Auction(const PPMarketSingleton& ppMarketSingleton, int position, int mybid);

    bool Pass();
    
    //void ReplacePowerPlant(<shared_ptr<PowerPlant>>, int);
    
	int getHighestPowerPlant();
    bool HasElektro(int elektro);

	// overloading assignment operator
	/*const Player& operator = (const Player &player);*/

	// overloading output operator
	 
	friend std::ostream& operator<<(std::ostream& outs, const HouseColor& color);
	friend std::ostream& operator<<(std::ostream& outs, const Player& player);
    
    /** Strategy Design Pattern for PlayerBehaviour **/
    Player(PlayerBehaviour* iniBehaviour);
    Player(PlayerBehaviour* iniBehaviour, string name, int electro, HouseColor color);
    void setPlayerBehaviour(PlayerBehaviour* newBehaviour);
    void executePlayerBehaviour();
};

