//
//  PlayerBehaviour.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <string>
using namespace std;

/** Strategy Design Pattern for the player beahaiour**/

// Strategy Abstract Class
class PlayerBehaviour
{
public:
    virtual string executeBehaviour() = 0; // pure virtual function for polymorphism
	virtual string executeAuction(bool& Initialbid, int& currentbid) = 0;
	virtual string executeAuction(bool& Initialbid, int& currentbid, int PPindex) = 0;

};




