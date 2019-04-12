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
	return "I'm an Environmentalist Player\n";
    
}
string EnviroPlayer::executeAuction(bool& Initialbid, int& currentbid) {
	if (Initialbid == true)
		return "BID";
	return "PASS";
}

string EnviroPlayer::executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
	return "";
}

int EnviroPlayer::executeAuction(int& currentbid) {
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