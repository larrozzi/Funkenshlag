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
using std::cin;
using std::cerr;
using std::shared_ptr;

// constructor | destructor
Building::Building() {}
//Building::Building(Player cPlayer) : currentPlayer(cPlayer) {}

Building::~Building() {}


// getters
shared_ptr<GameMap>& Building::getMap() { return map; }
int Building::getPlayPhase() const { return playPhase; }
int Building::getPlayStep() const { return playStep; }
vector<shared_ptr<Player>>& Building::getPlayerOrder() { return playerOrder; }

// setters
void Building::setMap(shared_ptr<GameMap>& map) { this->map = map; }
void Building::setPlayPhase(int phase) { this->playPhase = phase; }
void Building::setPlayStep(int step) { this->playStep = step; }

// new game
void Building::NewGame(MapLoader map, int numbPlayer)
{
    cout << "Map: " << map.getFileName() << ". Number of players: " << numbPlayer << endl;
    
    // add players to player vector
    while(numbPlayer > 0)
    {
        players.push_back(std::make_shared<Player>("",nullptr,50));
    }
    // player initial Elektros = 50
    for(Player player : players)
    {
        player->setElektro(50);
    }
    // player order
    for(Player player : players)
        playerOrder.push_back(player);
    
    random_shuffle(playerOrder.begin(), playerOrder.end());
    currentPlayer = playerOrder[0];
}

// used to determine the player turn order
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

// updating player order
void Building::updatePlayOrder(bool reverse) {
    sort(playerOrder.begin(), playerOrder.end(), playerPriority);
    
    if (reverse) // if reverse is true= reverses the player order
        std::reverse(playerOrder.begin(), playerOrder.end());
}

// next player in the player order
int Building::getNextPlayer()
{
    return (distance(playerOrder.begin(), find(playerOrder.begin(), playerOrder.end(), currentPlayer)) + 1) % playerOrder.size();
}

// Start Phase 4
void Building::BeginPhase4()
{
    cout << "Beginning Phase 4..." << endl;
    playPhase = 4; // set the phase to 4

    // player order - reverse
    updatePlayOrder(true);
    currentPlayer = playerOrder[0];

    Phase4Intro();
}

void Building::Phase4Intro()
{
    cout << "Enter a city you would like to build a house in: " << endl;
    string city;
    cin >> city;
    pickedCity->setName(city);
    currentPlayer->readFile();
    currentPlayer->buildinCity(city);
    pickedCity.reset();
}

void Building::Phase4BuyingCities()
{
    // player skipped, go to next player
    if(!pickedCity)
    {
         currentPlayer = playerOrder[getNextPlayer()]; // go to next player
         
         if(currentPlayer.get() == playerOrder[0].get())
             return EndPhase4();
         
         return Phase4Intro();
    }
    
    // if city is full
    if (pickedCity->getNumberOfHouses() == playStep) {
        cerr << "Cannot buy house " + pickedCity->getName() + " .City is full!";
        return Phase4Intro();
    }
    
    // cost of connecting to city
    int connectionCost;
    if (currentPlayer->getHouses().empty()) {
        connectionCost = pickedCity->getHousePrice();
    }
    else {
        connectionCost = pickedCity->getHousePrice() + map->getShortestPath(currentPlayer, pickedCity->getName());
    }
    
    // does player have enough Elektros?
    if(!currentPlayer->HasElektro(connectionCost))
    {
        cerr << "Not enough Elektros to buy " + pickedCity->getName()
        + " for a build cost of " + std::to_string(connectionCost) + "Elektros";
        return Phase4Intro();
    }
    
    // buy city
    auto anotherHouse = std::make_shared<House>(pickedCity, currentPlayer->getColor());
    anotherHouse->setPrice(connectionCost); // set the connectionCost has price of the house
    
    // does player have enough Elektros
    if(!currentPlayer->HasElektro(anotherHouse->getPrice()))
    {
        cerr << "Error!, Not enough Elektros to buy this house\n";
        return Phase4Intro();
    }
    
    // player has Elektros
    currentPlayer->buyHouse(anotherHouse);
       cout << "Succesfull in Buying the City" << endl;
       cout << currentPlayer->getName() + " has succesfully bought a house at "
       + pickedCity->getName() + " for a total cost of " << connectionCost << " Elektros" << endl;
       
    // buy another house
    return Phase4Intro();
}

void Building::EndPhase4()
{
    // if PowerPlants in the market have a price <= the highest number of cities owned by a player,
    // replace
    int maximumHouse = 0;
    for(shared_ptr<Player> p : players)
        
    cout << *currentPlayer << endl;
}
