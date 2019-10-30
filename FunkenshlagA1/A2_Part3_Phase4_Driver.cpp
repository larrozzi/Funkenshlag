////
////  A2_Part3_Phase4_Driver.cpp
////  FunkenshlagA1
////
////  Created by Alek Faruq Aliu on 2019-03-24.
////  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include "Building.h"
//#include "Player.h"
//#include "MapLoader.h"
//#include "GameMap.h"
//using namespace std;
//
//int main()
//{
//    MapLoader mapLoader = MapLoader();
//    GameMap gameMap = GameMap(mapLoader.readMap("map.txt")); // read Gamemap
//    gameMap.showMap(); // display Gamemap
//
//    Building phase4 = Building(); // Building phase
//
//    int numberPlayers = 0;
//    cout << std::endl;
//    while (numberPlayers < 2 || numberPlayers > 6) {
//        cout << "Number of players should be between 2 and 6." << endl;
//        cout << "Enter Number of players \n> ";
//        cin >> numberPlayers;
//    }
//
//    phase4.NewGame(mapLoader, numberPlayers); // initialize players
//    phase4.BeginPhase4();
//    phase4.Phase4BuyingCities();
//    phase4.EndPhase4();
//
//    system("pause");
//    return 0 ;
//}
