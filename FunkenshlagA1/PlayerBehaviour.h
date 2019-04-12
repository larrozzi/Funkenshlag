//
//  PlayerBehaviour.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <string>
#include "PowerPlantCards.h"
#include "ResourceMarket.h"
using namespace std;

/** Strategy Design Pattern for the player beahaiour**/

// Strategy Abstract Class
class PlayerBehaviour
{
public:
    virtual string executeBehaviour() = 0; // pure virtual function for polymorphism
    virtual string executeAuction(bool& Initialbid, int& currentbid) = 0;
    virtual string executeAuction(bool& Initialbid, int& currentbid, int PPindex) = 0;
	virtual int executeAuction(int& currentbid)=0;

	virtual int executeAuction(int& currentbid, int PPindex, bool returnIndex) = 0;
    virtual Type executeResourceMarket() = 0;
};




