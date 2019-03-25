//
//  Building.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-24.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <algorithm>
#include "Building.h"
using std::cout;
using std::cerr;

Building::Building() {}
Building::Building(Player cPlayer) : currentPlayer(cPlayer) {}

Building::~Building() {}

bool Building::addHouse(House* house)
{
    if(houses.size() == MAX_HOUSES)
        return false;
    houses.push_back(house);
    return true;
}

bool Building::isFull() const
{
    return houses.size() == MAX_HOUSES;
}

bool Building::isConnected(CityNode cityNames)
{
    for(auto connection = cityNames.getEdges().begin(); connection != cityNames.getEdges().end(); connection++)
    {
        //if((*connection))
    }
    return true;
}

// to determine the player turn order
bool playerPriority(shared_ptr<Player> p1, shared_ptr<Player> p2) {
    
    // Priority 1 - based on number of Houses
    if (p1->grabhouses().size() > p2->grabhouses().size())
        return true;
    
    if (p1->grabhouses().size() < p2->grabhouses().size())
        return false;
    
    // Priority2 - based on Highest powerplant
    if (p1->getHighestPowerPlant() > p2->getHighestPowerPlant())
        return true;
    
    return false;
}

// next player in the player order
int Building::getNextPlayer()
{
    return (distance(playerOrder.begin(), find(playerOrder.begin(), playerOrder.end(), currentPlayer)) + 1) % playerOrder.size();
}

// player order
void Building::updatePlayOrder(bool reverse) {
    sort(playerOrder.begin(), playerOrder.end(), playerPriority);
    
    if (reverse) // reverses the player order
        std::reverse(playerOrder.begin(), playerOrder.end());
}

// Start Phase 4
void Building::BeginPhase4()
{
    cout << "Beginning Phase 4..." << endl;
    playPhase = 4;

    // player order - reverse
    updatePlayOrder(true);
    currentPlayer = playerOrder[0];

    Phase4BuyingCities();
}

void Building::Phase4BuyingCities()
{
    cout << "Enter a city you would like to build a house in: " << endl;
    string city;
    cin >> city;
    pickedCity->setName(city);
    currentPlayer->readFile();
    currentPlayer->buildinCity(city);

    // player skipped
    if(!pickedCity)
    {
         currentPlayer = playerOrder[getNextPlayer()]; // go to next player
         
         if(currentPlayer.get() == playerOrder[0].get())
             return EndPhase4();
         
         return Phase4BuyingCities();
    }
    
    // if city is full
    if (pickedCity->getNumberOfHouses() == playStep) {
        cerr << "Cannot buy house " + pickedCity->getName() + " .City is full!";
        return Phase4BuyingCities();
    }
    
    // cost of connecting to city
    int buildCost;
    if (currentPlayer->grabhouses().empty()) {
        buildCost = pickedCity->getHousePrice();
    } else {
        buildCost = pickedCity->getHousePrice();
    }
    
    // if player has enough Elektros
    if(!currentPlayer->HasElektro(buildCost))
    {
        cerr << "Not enough Elektros to buy " + pickedCity->getName()
        + " for a build cost of " + std::to_string(buildCost) + "Elektros";
        return Phase4BuyingCities();
    }
    
    // buy the house
    //auto newHouse =
}
void Building::EndPhase4()
{
    cout << *currentPlayer << endl;
}
