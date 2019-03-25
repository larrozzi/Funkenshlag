//
//  Building.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-03-24.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "House.h"
#include "PowerPlantCards.h"
#include "Resource.h"
#include "GameMap.h"
#include "Step3Card.h"
#include "CityNode.h"
#include "MapLoader.h"
#include "GameMap.h"

using std::shared_ptr;
using std::vector;

class Building
{
private:
    vector<House*> houses;
    vector<shared_ptr<CityNode>> cities;
    shared_ptr<Player> currentPlayer; // current player
    vector<shared_ptr<Player>> playerOrder; // player order
    shared_ptr<CityNode> pickedCity = nullptr; // picked City
    shared_ptr<PowerPlantCards> highestPowerPlant;
    int playPhase = 0;
    int playStep = 0;
    
public:
    Building();
    Building(Player cPlayer);
    ~Building();
    
    void updatePlayOrder(bool reverse);
    int getNextPlayer();
    void BeginPhase4();
    void Phase4BuyingCities();
    void EndPhase4();
    
};


