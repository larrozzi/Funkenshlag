//
//  EnviroPlayer.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <string>
#include "PlayerBehaviour.h"

// A concrete Strategy that implements a environmentalistPlayer
class EnviroPlayer : public PlayerBehaviour
{
public:
    EnviroPlayer();
    ~EnviroPlayer();

	string executeBehaviour();

	string executeAuction(bool& Initialbid, int& currentbid);

	string executeAuction(bool& Initialbid, int& currentbid, int PPindex);

	int executeAuction(int& currentbid) ;

	int executeAuction(int& currentbid, int PPindex, bool returnIndex);
};

