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
#include "GameFunctions.cpp"

using namespace std;

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

 /*   EnviroPlayer enviroPlay;
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

	cout << "Hello and Welcome to Powergrid\n\n";
	  /*  cout << "Enter the Number of Players\n" << "> ";
	    cin >> NumofPlayers;*/
	
	  /*  while (NumofPlayers < 2 || NumofPlayers > 6) {
	        cout << "Number of players should be between 2 and 6." << endl;
	        cout << "Enter the Number of Players\n" << "> ";
	        cin >> NumofPlayers;
	    }*/
	
	            ///configuring the players one by one
		for (int i = 0; i < 3; ++i) {
			///creating a Player
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
			while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK") || alreadyPickedClr) {
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
			cin >> strategychoice;

			switch (strategychoice) {
			case 1:

				///initializing a Player
				players.push_back(make_shared<Player>(&enviroPlay, name, 50, clr));
				players.at(i)->executePlayerBehaviour();
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;

			case 2:
				///initializing a Player
				players.push_back(std::make_shared<Player>(&modPlay, name, 50, clr));
				players.at(i)->executePlayerBehaviour();
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;
			case 3:
				///initializing a Player
				players.push_back(std::make_shared<Player>(&aggPlay, name, 50, clr));
				players.at(i)->executePlayerBehaviour();
				/// taking 22 house items
				players.at(i)->grabhouses();
				/// taking an overview card
				cout << overviewCard;
				break;
			}
		}
		GameFunctions newgame;
		newgame.RandomplayerOrder();
		newgame.setupDeckCards();
		newgame.AuctionTime();

    return 0 ;
}
