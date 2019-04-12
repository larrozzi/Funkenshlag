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

using std::string;
/** Strategy Design Pattern for the player beahaiour**/

// Strategy Abstract Class
class PlayerBehaviour
{
public:
    virtual string executeBehaviour(PowerPlantCards* pp, ResourceMarket* market, Resource* resType, string bidPass, int bid) = 0; // pure virutual function for polymorphism
    virtual void executeAuction(std::shared_ptr<PowerPlantCards>pp, string bidPass) = 0;
    //virtual Type executeResourceMarket(ResourceMarket* market, string bidPass, int bid);
    virtual Type executeResourceMarket() = 0;
};
