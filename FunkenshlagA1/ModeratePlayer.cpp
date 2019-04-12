//
//  ModeratePlayer.cpp
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "ModeratePlayer.h"
#include <iostream>
using namespace std;

ModeratePlayer::ModeratePlayer() {}
ModeratePlayer::~ModeratePlayer() {}

// Moderate Behaviour
string ModeratePlayer::executeBehaviour()
{
    return "I'm a Moderate Player \n";
}

 string ModeratePlayer::executeAuction(bool& Initialbid, int& currentbid) {
     if (Initialbid == true)
         return "BID";
     return "PASS";
}

 string ModeratePlayer::executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
     return "";
 }

 int ModeratePlayer::executeAuction(int& currentbid) {

     int mybid = currentbid++;
     return mybid;
 }

 int ModeratePlayer::executeAuction(int& currentbid, int PPindex, bool returnIndex) {
	 if (returnIndex == false) {
		 currentbid = 3;
		 return currentbid++;
	 }
	 else {
		 PPindex = 0;
		 return PPindex;
	 }
		 
 }

Type ModeratePlayer::executeResourceMarket()
{
    Type resType = NONE;
    int random = rand() % 2 + 1; // random number b/w 1=COAL and 2=NONE
    switch (random) {
        case 1:
            resType = COAL;
            return resType;
        case 2:
            resType = NONE;
            return resType;
        default:
            return NONE;
    }
}
