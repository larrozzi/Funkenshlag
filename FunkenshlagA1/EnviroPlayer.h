//
//  EnviroPlayer.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "PlayerBehaviour.h"

// A concrete Strategy that implements a environmentalistPlayer
class EnviroPlayer : public PlayerBehaviour
{
public:
    EnviroPlayer();
    ~EnviroPlayer();
    string executeBehaviour(PowerPlantCards* pp, ResourceMarket* market, Resource* resType, string bidPass, int bid);
    void executeAuction(std::shared_ptr<PowerPlantCards>pp, string bidPass);
    Type executeResourceMarket();
};
