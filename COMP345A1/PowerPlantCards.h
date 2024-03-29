//
//  PowerPlantCards.h
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <iostream>
#include <stdio.h>
#include "Cards.h"
#include <vector>

using std::vector;

//enum ResourceType;

class PowerPlantCards : public Cards
{
private:
    int cardValue;  // the min bid of the power plant
    int numbResource; // how many number of resources the card need
    int capacity;   // how many resources can be taken => 2* #resource
    int powerHouse; // how many house can be powered
    
    //std::vector<ResourceType> activeResource; // what is the active resource
    
public:
    PowerPlantCards();
    PowerPlantCards(int cardValue, int numbResource, int capacity, int powerHouse);
    ~PowerPlantCards();
    
    // setters
    void setCardValue(int cardValue);
    void setResource(int numbResource);
    void setCapacity(int capacity);
    void setPowerHouse(int powerHouse);
    
    // getters
    int getCardValue() const;
    int getNumbResource() const;
    int getCapacity() const;
    int getPowerHouse() const;
    
    //static vector<PowerPlantCards>createPowerPlantCards();
    static void printCards(vector<PowerPlantCards>vector);
    
    // overloading the output operator
    friend std::ostream& operator << (std::ostream& outs, const PowerPlantCards& card);
    
};
