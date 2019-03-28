//
//  Building.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-24.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <algorithm>
#include <memory>
#include "Building.h"
using std::cout;
using std::cin;
using std::cerr;
using std::shared_ptr;

// constructor | destructor
Building::Building() {}
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

// convert HouseColor string to enum
HouseColor convert(const std::string clr)
{
    if (clr == "NO_COLOR")      return NO_COLOR;
    else if (clr == "RED")      return RED;
    else if (clr == "BLUE")     return BLUE;
    else if (clr == "GREEN")    return GREEN;
    else if (clr == "YELLOW")   return YELLOW;
    else if (clr == "BLACK")    return BLACK;
    else if (clr == "PINK")     return PINK;
    else return NO_COLOR;
}

// new game - configure players
void Building::NewGame(MapLoader map, int numbPlayer)
{
    cout << "Map: " << map.getFileName() << ". Number of players: " << numbPlayer << " players" << endl;
    
    string pName;
    string color;
    HouseColor clr;
	bool alreadyPicked = false;
    
    for (int i = 0; i < numbPlayer; i++)
    {
        cout << "Please Enter Player Name\n> ";
        cin >> pName;

        cout << "Please Enter House Color: RED, BLUE, GREEN, YELLOW, BLACK, PINK \nColor > ";
        cin >> color;
		for (int i = 0; i < players.size(); i++) {
			if (players.at(i)->getColor() == clr) {
				alreadyPicked = true;
			}
		}
		while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK") || alreadyPicked) {
			cout << "Please pick a valid color (either you entered an invalid color or the color was already picked by another player)." << endl;
			cout << "Please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
			cout << "> ";
			cin >> color;
			clr = convert(color);

			for (int i = 0; i < players.size(); i++) {
				if (players.at(i)->getColor() == clr) {
					alreadyPicked = true;
				}
				else {
					alreadyPicked = false;
				}
			}
		}
		players.push_back(make_shared<Player>(pName, 50, clr));
	}
    
    // player order
    for(shared_ptr<Player> player : players) {
        playerOrder.push_back(player);
    }
    random_shuffle(playerOrder.begin(), playerOrder.end()); // initial shuffle of order
    
    // print player order
    cout << "Player order is: " << endl;
    for (int i = 0; i < numbPlayer; ++i)
    {
         cout << "[" << (i+1) << "] " << players.at(i)->getName() << endl;
    }
    currentPlayer = playerOrder[0]; // set current player turn
    //cout << "Done with NewGame" << endl;
	cout << "------------------------------------------" << endl;
}

// used to determine the player turn order
bool playerPriority(shared_ptr<Player> p1, shared_ptr<Player> p2) {
    
    // priority1 - based on number of Houses owned
    if (p1->getOwnedHouses().size() > p2->getOwnedHouses().size())
        return true;
    
    if (p1->getOwnedHouses().size() < p2->getOwnedHouses().size())
        return false;
    
    // priority2 - based on Highest powerplant owned
    if (p1->getHighestPowerPlant() > p2->getHighestPowerPlant())
        return true;
    
    return false;
}

// updating player order
void updatePlayOrder(bool reverse, vector<shared_ptr<Player>> playerOrder) {
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
    updatePlayOrder(true, playerOrder);
    currentPlayer = playerOrder[0];

    Phase4Intro();
}

void Building::Phase4Intro()
{
	cout << "\nPlayer " << currentPlayer->getName() << " " << currentPlayer->getElektro() << " Elektros" << endl;
	cout << "Would you like to Build or Pass?" << endl;
	cin >> BuildOrPass;

	if (BuildOrPass == "Pass")
	{
		return Phase4BuyingCities();
	}

	if (BuildOrPass == "Build")
	{
		cout << "Enter a city you would like to build a house in: " << endl;
		cin >> city;
		currentPlayer->readFile(); // read map file
		currentPlayer->buildinCity(city); // build in city
		pickedCity.reset();
	}
}
   

void Building::Phase4BuyingCities()
{
    // player skipped, go to next player
    //if(pickedCity->getName() != city)
	//if (BuildOrPass == "Pass")
	if (!pickedCity)
    {
         currentPlayer = playerOrder[getNextPlayer()]; // go to next player

         if(currentPlayer.get() == playerOrder[0].get())
             return EndPhase4();
         
         return Phase4Intro();
    }
    
    // if city is full
    if (pickedCity->getNumberOfHouses() == playStep) {
        cerr << "Cannot buy house " << pickedCity->getName() << ". City is full!";
        return Phase4Intro();
    }
    
    // cost of connecting to city
    if (currentPlayer->getOwnedHouses().empty()) {
        connectionCost = pickedCity->getHousePrice();
    }
    else {
        connectionCost = pickedCity->getHousePrice() + map->getShortestPath(currentPlayer, pickedCity->getName());
    }
    // does player have enough Elektros?
    if (!currentPlayer->HasElektro(connectionCost))
    {
		cerr << "Not enough Elektros to buy " << pickedCity->getName()
			 << " for a build cost of " << connectionCost << "Elektros";
		return Phase4Intro();
	} 

	// buy city
	auto newHouse = std::make_shared<House>(currentPlayer->getColor());
	newHouse->setPrice(connectionCost); // set the connectionCost has price of the house

	// does player have enough Elektros
	if (!currentPlayer->HasElektro(newHouse->getPrice()))
	{
		cerr << "Error!, Not enough Elektros to buy this house\n";
		return Phase4Intro();
	}
	// player has Elektros
	currentPlayer->buyHouse(newHouse);
	cout << "Succesfull in Buying the City" << endl;
	cout << currentPlayer->getName() + " has succesfully bought a house at "
	+ pickedCity->getName() + " for a total cost of " << connectionCost << " Elektros" << endl;

	// buy another house
	return Phase4Intro();

}

void Building::EndPhase4()
{
	cout << "End of Phase 4" << endl;
	cout << "------------------------------------------" << endl;

	// if PowerPlants in the market have a price <= the highest number of cities owned by a player, replace
	int maximumHouse = 0;
	for (shared_ptr<Player> p : players) {
		if (p->getOwnedHouses().size() > maximumHouse)
			maximumHouse = p->getOwnedHouses().size();
	}

	/*
	vector<PowerPlantCards> PPcards = PowerPlantCards::createPowerPlantCards();
	while (PPcards[0].getCardValue() <= maximumHouse) {
		PPcards.RemoveLowestVisible();
		PPcards.DrawPlant();
	}
	// Check if we drew the step 3 card
	if (PPcards.GetJustDrewStep() == 3) {
		PPcards.AdjustForStep3();
		PPcards.ShuffleStack();
		playStep = 3;
		cout << "Entering Step 3." << endl;
	}
	// Go to Phase 5
	*/

	// Print Player info
	cout << "Player possession: " << endl;
	for (shared_ptr<Player> p : players) {
		cout << *p << endl;
	}
}
