//
//  PlayerBehaviour.h
//  FunkenshlagA1
//
//  Created by Alek Faruq Aliu on 2019-04-10.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

class PlayerBehaviour
{
public:
    virtual void executeBehaviour() = 0; // pure virutual function for polymorphism
};

class aggressivePlayer : public PlayerBehaviour
{
public:
    void executeBehaviour() {
        
    }
};

class moderatePlayer : public PlayerBehaviour
{
    void executeBehaviour() {
        
    }
};

class environmentalistPlayer : public PlayerBehaviour
{
    void executeBehaviour() {
        
    }
};
