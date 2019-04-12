//
//  A3_Part3_Stratergy_Driver.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-09.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>

#include "Building.h"
#include "Player.h"
#include "MapLoader.h"
#include "GameMap.h"
#include "Player.h"
#include "CityNode.h"
#include "SummaryCards.h"

#include "PlayerBehaviour.h"
#include "EnviroPlayer.h"
#include "AggressivePlayer.h"
#include "ModeratePlayer.h"

using namespace std;


// method that converts Type to string
string Type2String(Type t) {
    switch (t) {
        case COAL:
            return "COAL";
        case OIL:
            return "OIL";
        case GARBAGE:
            return "GARBAGE";
        case URANIUM:
            return "URANIUM";
        default:
            return "NONE";
    }
}

// main                                                                                              
int main()
{
    vector<shared_ptr<Player>> players; // vector of players
    shared_ptr<Player> currentPlayer; // current player
    int i = 0; // current player index
    int numberOfPlayers = 0;
    
    // Different Player Behviour
    EnviroPlayer enviroPlay;
    ModeratePlayer modPlay;
    AggressivePlayer aggPlay;

    // Players with different Behaviours
    shared_ptr<Player> p1 = make_shared<Player>(&enviroPlay,"Faruq", 500, BLUE);
    shared_ptr<Player> p2 = make_shared<Player>(&modPlay,"Tao", 500, RED);
    shared_ptr<Player> p3 = make_shared<Player>(&aggPlay,"Yassine", 500, GREEN);
    
    // store players into players vector
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    
    numberOfPlayers = static_cast<int>(players.size()); // get the number of players
    
    cout << "WELCOME TO POWERPLANT AUCTION" << endl;
    shared_ptr<PowerPlantCards> card1 = make_shared<PowerPlantCards>(3, COAL, 100, 100, 1);
    shared_ptr<PowerPlantCards> card2 = make_shared<PowerPlantCards>(3, OIL, 100,100, 1);
    shared_ptr<PowerPlantCards> card3 = make_shared<PowerPlantCards>(3, URANIUM, 100, 100, 1);
    
    p2->OwnPowerPlant(card1);
    p2->OwnPowerPlant(card2);
    p2->OwnPowerPlant(card3);

    cout << "WELCOME TO RESOURCE BUYING\n" << endl;
    ResourceMarket* market = new ResourceMarket();
    std::cout << *market << std::endl; // print market
   
    currentPlayer = players[i]; // set current player to initial player in players vector
    string yOn = "";
    Type type = NONE;
    
    cout << "Player " << currentPlayer->getName() << ", ";
    cout << "Would you like to buy resources?(Y/N): > ";
    cin >> yOn;
    
    while (yOn == "N")
    {
        currentPlayer = players[++i]; // go to next player
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "Would you like to buy resources?(Y/N): > ";
        cin >> yOn;
        
        // reset player order
//        if (i == numberOfPlayers-1) {
//            i = -1;
//        }
        
        // all players skipped, no players buying resources ==> END OF RESOURCE BUYING
        if (i >= numberOfPlayers-1) {
            break;
        }
    }
    
    while (yOn == "Y")
    {
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "What type of resource would you like to buy? (COAL,OIL,GARBAGE,URANIUM): > ";
        type = currentPlayer->executeResourceMarket(); // get the Resource Type
        cout << Type2String(type) << endl; // convert Type to string
        
        currentPlayer->buyResource(type, market); // buy the resource
        cout << *market << endl;
        cout << *currentPlayer << endl;
        
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "Would you like to buy more resources?(Y/N): > ";
        cin >> yOn;
        
        if (yOn == "N")
        {
            currentPlayer = players[++i]; // go to next player
            cout << "Player " << currentPlayer->getName() << ", ";
            cout << "Would you like to buy resources?(Y/N): ";
            cin >> yOn;
            
            if (i >= numberOfPlayers-1) {
                break;
            }
        }
    }
    cout << "\nEnd of Resource Buying";
    // Print players inventory
    for (int i = 0; i < players.size(); ++i) {
        cout << *players[i] << endl;
    }
    
    // Deallocation of memory
    delete market; market = nullptr;
    //system("pause");
    return 0;
}



//    MapLoader mapLoader = MapLoader();
//    GameMap gameMap = GameMap(mapLoader.readMap("map.txt")); // read Gamemap
//    gameMap.showMap(); // display Gamemap
//    Building phase4 = Building(); // Building phase
//    int numberPlayers = 0;
//    cout << std::endl;
//
//    while (numberPlayers < 2 || numberPlayers > 6) {
//        cout << "Number of players should be between 2 and 6." << endl;
//        cout << "Enter Number of players \n> ";
//        cin >> numberPlayers;
//    }
//    phase4.NewGame(mapLoader, numberPlayers); // initialize players
//
//
//    system("pause");
