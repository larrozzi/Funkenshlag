//
//  EnviroPlayer.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "EnviroPlayer.h"
#include <iostream>
using namespace std;

EnviroPlayer::EnviroPlayer() {};
EnviroPlayer::~EnviroPlayer() {};

// Evironmentalist Behaviour
string EnviroPlayer::executeBehaviour(PowerPlantCards* pp, ResourceMarket* market, Resource* resType, string bidPass, int bid)
{
    return "I'm an Environmentalist Player\n";
}

void EnviroPlayer::executeAuction(std::shared_ptr<PowerPlantCards>pp, string bidPass)
{
    cout << "Auction Environmental Player\n";
    
    if(pp->getNumbResource() == 0)
        bidPass = "BID";
    else
        bidPass = "PASS";
}

Type EnviroPlayer::executeResourceMarket()
{
    Type resType = NONE;
    return resType;
}
