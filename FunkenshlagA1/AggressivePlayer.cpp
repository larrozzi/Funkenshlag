//
//  AggressivePlayer.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "AggressivePlayer.h"
#include <iostream>
using namespace std;

AggressivePlayer::AggressivePlayer() {}
AggressivePlayer::~AggressivePlayer() {}

// Aggressive Behaviour
string AggressivePlayer::executeBehaviour()
{
  return "I'm an Aggressive Player\n" ;

}


string AggressivePlayer::executeAuction(bool& Initialbid, int& currentbid) {
	return "";
}


string AggressivePlayer:: executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
	return "";
}

Type AggressivePlayer::executeResourceMarket()
{
    Type resType = NONE;
    srand(time(NULL));
    
    int random = rand() % 3 + 1; // random number b/w 1 and 3
    switch (random) {
        case 1:
            resType = COAL;
            return resType;
        case 2:
            resType = OIL;
            return resType;
        case 3:
            resType = URANIUM;
            return resType;
        default:
            return NONE;
    }
}
