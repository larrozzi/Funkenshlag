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
string EnviroPlayer::executeBehaviour()
{
    return "Environmentalist Player\n";
    
}
string EnviroPlayer::executeAuction(bool& Initialbid, int& currentbid) {
    if (Initialbid == true)
        return "BID";
    return "PASS";
}

string EnviroPlayer::executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
    return "";
}

int EnviroPlayer::executeAuction(int& currentbid)
{
	int mybid = currentbid++;
	return mybid;
}

int EnviroPlayer::executeAuction(int& currentbid, int PPindex, bool returnIndex) {
	if (returnIndex == false) {
		currentbid = 5;
		return currentbid++;
	}
	else {
		PPindex = 2;
		return PPindex;
	}
}
		
Type EnviroPlayer::executeResourceMarket()
{
    Type resType = NONE; // no need to buy resource for ECOFUSION powerplants
    srand(time(NULL));
    int random = rand() % 3 + 1; // random number b/w 1 and 3
    switch (random) {
        case 1:
            resType = COAL;
            return resType;
        case 2:
            resType = NONE;
            return resType;
        case 3:
            resType = GARBAGE;
            return resType;
        default:
            return NONE;
    }
}
