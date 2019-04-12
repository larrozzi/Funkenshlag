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
	if (Initialbid == true)
		return "BID";
	return "BID";
}


string AggressivePlayer:: executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
	return "";
}

int AggressivePlayer::executeAuction( int& currentbid) {
	
	int mybid = currentbid++;
	return mybid;
}


int AggressivePlayer::executeAuction(int& currentbid, int PPindex, bool returnIndex) {
	if (returnIndex == false) {
		currentbid = 6;
		return currentbid++;
	}

	PPindex = 3;
	return PPindex;
}