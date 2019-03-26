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
    shared_ptr<Player> players;
    vector<House*> houses;
    vector<shared_ptr<CityNode>> cities;
    shared_ptr<Player> currentPlayer; // current player
    vector<shared_ptr<Player>> playerOrder; // player in current order
    shared_ptr<PowerPlantCards> highestPowerPlant; // used for player order
    shared_ptr<GameMap> map;
    int playPhase = 0; // current phase | initial = 0
    int playStep; // current step of the game (step 1, 2, 3)
    
public:
    Building();
    //Building(Player cPlayer);
    ~Building();
    
    // getters
    shared_ptr<GameMap>& getMap();
    int getPlayPhase() const;
    int getPlayStep() const;
    vector<shared_ptr<Player>>& getPlayerOrder();
    
    // setters
    void setMap(shared_ptr<GameMap>& map);
    void setPlayPhase(int phase);
    void setPlayStep(int step);
    void updatePlayOrder(bool reverse);
    
    void NewGame(MapLoader map, int numbPlayer);
    
    // Phase 4 Buying Cities
    shared_ptr<CityNode> pickedCity = nullptr; // picked City
    int getNextPlayer();
    void BeginPhase4();
    void Phase4Intro()
    void Phase4BuyingCities();
    void EndPhase4();
};


