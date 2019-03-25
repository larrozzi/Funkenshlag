//
//  A2_Part3_Phase4_Driver.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-24.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Building.h"
#include "Player.h"
#include "MapLoader.h"
#include "GameMap.h"


int main ()
{
    MapLoader mapLoader = MapLoader();
    GameMap gameMap = GameMap(mapLoader.readMap("map.txt"));
    for (CityNode x : gameMap.getMap())
    {
        vector<string> eT = x.getEdges();
        vector<string> cT = x.getCosts();
        cout << x.getName() + '|';
        for (string i : x.getEdges())
        {
            cout << i + ',';
        }
        cout << '|';
        for (int i = 0; i < eT.size(); i++)
        {
            cout << cT[i] + ',';
        }
        cout << endl;
    }
    
    Player p1 = Player("Faruq", 50, BLUE);
    Building phase4 = Building(p1);
    phase4.BeginPhase4();
    phase4.EndPhase4();
    
    return 0 ;
}
