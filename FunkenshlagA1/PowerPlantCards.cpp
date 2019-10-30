//
//  PowerPlantCards.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "PowerPlantCards.h"

using std::vector;

// constructors
PowerPlantCards::PowerPlantCards() {}
PowerPlantCards::PowerPlantCards(int cardValue, Type resourceType, int numbResource, int capacity, int powerHouse)
	: cardValue(cardValue), resourceType(resourceType), numbResource(numbResource), capacity(2 * numbResource), powerHouse(powerHouse)
{/*NOTHING*/}

// destructor
PowerPlantCards::~PowerPlantCards() {}

// setters
void PowerPlantCards::setCardValue(int cardValue) { this->cardValue = cardValue; }
void PowerPlantCards::setResourceType(Type resourceType) { this->resourceType = resourceType; }
void PowerPlantCards::setResource(int numbResource) { this->numbResource = numbResource; }
void PowerPlantCards::setCapacity(int capacity) { this->capacity = capacity; }
void PowerPlantCards::setPowerHouse(int powerHouse) { this->powerHouse = powerHouse; }

// getters
int PowerPlantCards::getCardValue() const { return cardValue; }
Type PowerPlantCards::getResourceType() const { return resourceType; }
int PowerPlantCards::getNumbResource() const { return numbResource; }
int PowerPlantCards::getCapacity() const { return 2 * numbResource; }
int PowerPlantCards::getPowerHouse() const { return powerHouse; }

// method to create the PowerPlantCards
vector<PowerPlantCards>PowerPlantCards::createPowerPlantCards()
{
    vector<PowerPlantCards>myCards;
    
    // lowest card value
    myCards.push_back(PowerPlantCards(3,OIL,2,4,1));
    myCards.push_back(PowerPlantCards(4,COAL,2,4,1));
    myCards.push_back(PowerPlantCards(5,HYBRID,2,4,1));
    myCards.push_back(PowerPlantCards(6,GARBAGE,1,2,1));
    myCards.push_back(PowerPlantCards(7,OIL,3,6,2));
    myCards.push_back(PowerPlantCards(8,COAL,3,6,2));
    myCards.push_back(PowerPlantCards(9,OIL,1,2,1));
    
    myCards.push_back(PowerPlantCards(10,COAL,2,4,2));
    myCards.push_back(PowerPlantCards(11,URANIUM,1,2,2));
    myCards.push_back(PowerPlantCards(12,HYBRID,2,4,2));
    myCards.push_back(PowerPlantCards(13,ECOFUSION,0,0,1));
    myCards.push_back(PowerPlantCards(14,GARBAGE,2,4,2));
    myCards.push_back(PowerPlantCards(15,COAL,2,4,3));
    myCards.push_back(PowerPlantCards(16,OIL,2,4,3));
    
    myCards.push_back(PowerPlantCards(17,URANIUM,1,2,2));
    myCards.push_back(PowerPlantCards(18,ECOFUSION,0,0,5));
    myCards.push_back(PowerPlantCards(19,GARBAGE,2,4,3));
    myCards.push_back(PowerPlantCards(20,COAL,3,6,5));
    myCards.push_back(PowerPlantCards(21,HYBRID,2,4,4));
    myCards.push_back(PowerPlantCards(22,ECOFUSION,0,0,2));
    myCards.push_back(PowerPlantCards(23,URANIUM,1,2,3));
    
    myCards.push_back(PowerPlantCards(24,GARBAGE,2,4,4));
    myCards.push_back(PowerPlantCards(25,COAL,2,4,5));
    myCards.push_back(PowerPlantCards(26,OIL,2,4,5));
    myCards.push_back(PowerPlantCards(27,ECOFUSION,0,0,3));
    myCards.push_back(PowerPlantCards(28,URANIUM,1,2,4));
    myCards.push_back(PowerPlantCards(29,HYBRID,1,2,4));
    myCards.push_back(PowerPlantCards(30,GARBAGE,3,6,6));
    
    myCards.push_back(PowerPlantCards(31,COAL,3,6,6));
    myCards.push_back(PowerPlantCards(32,OIL,3,6,6));
    myCards.push_back(PowerPlantCards(33,ECOFUSION,0,0,4));
    myCards.push_back(PowerPlantCards(34,URANIUM,1,2,5));
    myCards.push_back(PowerPlantCards(35,OIL,1,2,5));
    myCards.push_back(PowerPlantCards(36,COAL,3,6,7));
    myCards.push_back(PowerPlantCards(37,ECOFUSION,0,0,4));
    
    myCards.push_back(PowerPlantCards(38,GARBAGE,3,6,7));
    myCards.push_back(PowerPlantCards(39,URANIUM,1,2,6));
    myCards.push_back(PowerPlantCards(40,OIL,2,4,6));
    myCards.push_back(PowerPlantCards(42,COAL,2,4,6));
    myCards.push_back(PowerPlantCards(44,ECOFUSION,0,0,5));
    myCards.push_back(PowerPlantCards(46,HYBRID,3,6,7));
    myCards.push_back(PowerPlantCards(50,ECOFUSION,0,0,6));
    // highest card value
    
    return myCards;
}

// method to prints the PowerPlantCards
void PowerPlantCards::printPPCards(vector<PowerPlantCards>ppCards)
{
    std::vector<PowerPlantCards>::iterator show; // create a vector iterator
    for (show = ppCards.begin(); show != ppCards.end(); show++) {
        std::cout << *show << std::endl;
    }
}



// overloading output stream operator for PowerPlantCards
std::ostream& operator<<(std::ostream& outs, const PowerPlantCards& card)
{
    outs << "Card Value: " << card.cardValue << "\t\t Number of Resources: " << card.numbResource
    << "\t\t Max Resource Capacity: " << card.capacity << "\t\t Power Number of Houses: " << card.powerHouse;
    
    if(card.numbResource > 0) // if the resource size > 0, print out the resource name
    {
        outs << "\t\t Type of Resources: " << card.resourceType;
    }
    
    return outs;
}

