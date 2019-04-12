//
//  A3_Part3_Stratergy_Driver.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-09.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Building.h"
#include "Player.h"
#include "MapLoader.h"
#include "GameMap.h"
#include "CityNode.h"
#include "SummaryCards.h"

#include "PlayerBehaviour.h"
#include "EnviroPlayer.h"
#include "AggressivePlayer.h"
#include "ModeratePlayer.h"
#include "GameFunctions.h"

using namespace std;

static HouseColor convert(const std::string& clr)
{
	if (clr == "NO_COLOR")     return NO_COLOR;
	else if (clr == "RED")     return RED;
	else if (clr == "BLUE")    return BLUE;
	else if (clr == "GREEN")   return GREEN;
	else if (clr == "YELLOW")  return YELLOW;
	else if (clr == "BLACK")   return BLACK;
	else if (clr == "PINK")    return PINK;
	else return NO_COLOR;
}

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
    string name;
    string color;
    HouseColor clr;
    string cityName;
    SummaryCards overviewCard;
    bool alreadyPickedClr = false;
    vector<shared_ptr<Player>> players;
    int strategychoice;

    EnviroPlayer enviroPlay;
    ModeratePlayer modPlay;
    AggressivePlayer aggPlay;

 /* EnviroPlayer enviroPlay;
    ModeratePlayer modPlay;
    AggressivePlayer aggPlay;

    Player p1 = Player(&enviroPlay,"Faruq", 500, BLUE);
    Player p2 = Player(&modPlay,"Tao", 500, RED);
    Player p3 = Player(&aggPlay,"Yassine", 500, GREEN);

	p1.executePlayerBehaviour();
	p2.executePlayerBehaviour();
	p3.executePlayerBehaviour();*/
    
//    Player p1 = Player(new EnviroPlayer,"Faruq", 500, BLUE);
//    Player p2 = Player(new ModeratePlayer,"Tao", 500, RED);
//    Player p3 = Player(new AggressivePlayer,"Yassine", 500, GREEN);
    
    

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

	cout << "Hello and Welcome to PowerGrid\n";
	  /*  cout << "Enter the Number of Players\n" << "> ";
	    cin >> NumofPlayers;*/
	
	  /*  while (NumofPlayers < 2 || NumofPlayers > 6) {
	        cout << "Number of players should be between 2 and 6." << endl;
	        cout << "Enter the Number of Players\n" << "> ";
	        cin >> NumofPlayers;
	    }*/
	
        //configuring the players one by one
		for (int i = 0; i < 3; ++i) {
			//creating a Player
			cout << "" << endl;
			cout << "Please enter your name  \n";
			cout << "> ";
			cin >> name;
			cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
			cout << "> ";
			cin >> color;
			clr = convert(color);


			for (int i = 0; i < players.size(); i++) {
				if (players.at(i)->getColor() == clr) {
					alreadyPickedClr = true;
				}
			}
			while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK") || alreadyPickedClr)
            {
				cout << "Please pick a valid color (either you entered an invalid color or the color was already picked by another player)." << endl;
				cout << "Please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
				cout << "> ";
				cin >> color;
				clr = convert(color);
				for (int i = 0; i < players.size(); i++) {
					if (players.at(i)->getColor() == clr) {
						alreadyPickedClr = true;
					}
					else
						alreadyPickedClr = false;
				}
			}

			cout << "Pick the number coresponding to your strategy: \n";
			cout << "1: Environmental" << endl;
			cout << "2: Moderate" << endl;
			cout << "3: Aggressive" << endl;
            cout << "> ";
			cin >> strategychoice;

			switch (strategychoice) {
			case 1:
				///initializing a Player
				players.push_back(make_shared<Player>(&enviroPlay, name, 50, clr));
                cout << players[i]->getName() << ": " << players.at(i)->executePlayerBehaviour() << endl;
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;

			case 2:
				///initializing a Player
				players.push_back(std::make_shared<Player>(&modPlay, name, 50, clr));
				cout << players[i]->getName() << ": " << players.at(i)->executePlayerBehaviour() << endl;
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;
                    
			case 3:
				///initializing a Player
				players.push_back(std::make_shared<Player>(&aggPlay, name, 50, clr));
				cout << players[i]->getName() << ": " << players.at(i)->executePlayerBehaviour() << endl;
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;
			}
		}
//        GameFunctions* newgame= new GameFunctions();
//        cout << "Phase I" << endl;
//        cout << "Random Player order on first Auction as follows:" << endl;
//        cout << "" << endl;
//        cout << "----------------------------------------------------------------------------" << endl;
//        cout << "" << endl;
//
//        newgame->RandomplayerOrder(players);
//
//        newgame->setupDeckCards();
//
//        newgame->AuctionTime();

    
    
    shared_ptr<Player> currentPlayer; // current player
    int i = 0; // current player index
    int numberOfPlayers = 0;
    
    /*
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
    */
    
    numberOfPlayers = players.size(); // get the number of players
    
    /*
    cout << "WELCOME TO POWERPLANT AUCTION" << endl;
    shared_ptr<PowerPlantCards> card1 = make_shared<PowerPlantCards>(3, COAL, 100, 100, 1);
    shared_ptr<PowerPlantCards> card2 = make_shared<PowerPlantCards>(3, OIL, 100,100, 1);
    shared_ptr<PowerPlantCards> card3 = make_shared<PowerPlantCards>(3, URANIUM, 100, 100, 1);
    
    p2->OwnPowerPlant(card1);
    p2->OwnPowerPlant(card2);
    p2->OwnPowerPlant(card3); */
    
    cout << "\nWELCOME TO RESOURCE BUYING\n" << endl;
    ResourceMarket* market = new ResourceMarket();
    std::cout << *market << std::endl; // print market
    
    currentPlayer = players[i]; // set current player to initial player in players vector
    string yOn = "";
    Type type = NONE;
    
    cout << "Player " << currentPlayer->getName() << ", ";
    cout << "Would you like to buy resources?(Y/N): \n> ";
    cin >> yOn;
    
    while (yOn == "N" || yOn == "n")
    {
        // all players skipped, no players buying resources ==> END OF RESOURCE BUYING
        if (i >= numberOfPlayers-1) {
            break;
        }
        currentPlayer = players[++i]; // go to next player
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "Would you like to buy resources?(Y/N): \n> ";
        cin >> yOn;
    }
    
    while (yOn == "Y" || yOn == "y")
    {
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "What type of resource would you like to buy? (COAL,OIL,GARBAGE,URANIUM): \n> ";
        type = currentPlayer->executeResourceMarket(); // get the Resource Type
        cout << Type2String(type) << endl; // convert Type to string
        
        currentPlayer->buyResource(type, market); // buy the resource
        cout << *market << endl;
        cout << *currentPlayer << endl;
        
        cout << "Player " << currentPlayer->getName() << ", ";
        cout << "Would you like to buy more resources?--(Y/N): \n> ";
        cin >> yOn;
        
        while (yOn == "N" || yOn == "n")
        {
            if (i >= numberOfPlayers-1) {
                break;
            }
            currentPlayer = players[i++]; // go to next player
            cout << "Player " << currentPlayer->getName() << ", ";
            cout << "Would you like to buy resources?(Y/N): \n> ";
            cin >> yOn;
        }
    }
    cout << "\nEnd of Resource Buying";
    // Print players inventory
    for (int i = 0; i < players.size(); ++i) {
        cout << *players[i] << endl;
    }
    
    // deallocation of memory
    delete market; market = nullptr;
    
    //system("pause");
    return 0 ;
}
