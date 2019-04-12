//
//  ModeratePlayer.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "ModeratePlayer.h"
#include "ResourceMarket.h"
#include "PowerPlantCards.h"
#include <iostream>
using namespace std;

ModeratePlayer::ModeratePlayer() {}
ModeratePlayer::~ModeratePlayer() {}

// Moderate Behaviour

string ModeratePlayer::executeBehaviour(PowerPlantCards* pp, ResourceMarket* market, Resource* resType, string bidPass, int bid)
{
    if (resType->getType() == COAL) {
        bidPass = "BID";
        return bidPass;
    }
    return "I'm a Moderate Player \n";
}

void ModeratePlayer::executeAuction(std::shared_ptr<PowerPlantCards>pp, string bidPass)
{
    cout << "Auct. mod player\n";
}

Type ModeratePlayer::executeResourceMarket()
{
    Type resType = COAL;
    //cout << "ResourceMarket Moderate Player\n";
    
    return resType;
}
