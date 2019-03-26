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
    int numberPlayers = 2;
    MapLoader mapLoader = MapLoader();
    GameMap gameMap = GameMap(mapLoader.readMap("map.txt"));
    gameMap.showMap(); // display map
    
    
    Player p1 = Player("Faruq", 50, BLUE);
    
    Building phase4 = Building();
    
    phase4.NewGame(mapLoader, numberPlayers);
    
    phase4.BeginPhase4();
    phase4.EndPhase4();
    
    return 0 ;
}
