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

int main()
{
    EnviroPlayer enviroPlay;
    ModeratePlayer modPlay;
    AggressivePlayer aggPlay;
    
    Player p1 = Player(&enviroPlay,"Faruq", 500, BLUE);
    Player p2 = Player(&modPlay,"Tao", 500, RED);
    Player p3 = Player(&aggPlay,"Yassine", 500, GREEN);

    p1.executePlayerBehaviour();
    p2.executePlayerBehaviour();
    p3.executePlayerBehaviour();

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
    return 0 ;
}
