//
//  PowerPlantCards.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "PowerPlantCards.h"

using std::vector;

//enum ResourceType { COAL, OIL, GARBAGE, URANIUM, ECOFUSION };

// constructors
PowerPlantCards::PowerPlantCards() {}
PowerPlantCards::PowerPlantCards(int cardValue, int numbResource, int capacity, int powerHouse) : cardValue(cardValue), numbResource(numbResource), capacity(2*numbResource), powerHouse(powerHouse) {/*NOTHING*/}
// destructor
PowerPlantCards::~PowerPlantCards() {}

// setters
void PowerPlantCards::setCardValue(int cardValue) { this->cardValue = cardValue; }
void PowerPlantCards::setResource(int numbResource) { this->numbResource = numbResource; }
void PowerPlantCards::setCapacity(int capacity) { this->capacity = capacity; }
void PowerPlantCards::setPowerHouse(int powerHouse) { this->powerHouse = powerHouse; }

// getters
inline int PowerPlantCards::getCardValue() const { return cardValue; }
inline int PowerPlantCards::getNumbResource() const { return numbResource; }
inline int PowerPlantCards::getCapacity() const { return 2*numbResource; }
inline int PowerPlantCards::getPowerHouse() const { return powerHouse; }

// method to create the PowerPlantCards
vector<PowerPlantCards>PowerPlantCards::createPowerPlantCards()
{
    vector<PowerPlantCards>myCards;
    
    // lowest card value
    myCards.push_back(PowerPlantCards(3,2,4,1));
    myCards.push_back(PowerPlantCards(4,2,4,1));
    myCards.push_back(PowerPlantCards(5,2,4,1));
    myCards.push_back(PowerPlantCards(6,1,2,1));
    myCards.push_back(PowerPlantCards(7,3,6,2));
    myCards.push_back(PowerPlantCards(8,3,6,2));
    myCards.push_back(PowerPlantCards(9,1,2,1));

    myCards.push_back(PowerPlantCards(10,2,4,2));
    myCards.push_back(PowerPlantCards(11,1,2,2));
    myCards.push_back(PowerPlantCards(12,2,4,2));
    myCards.push_back(PowerPlantCards(13,0,0,1));
    myCards.push_back(PowerPlantCards(14,2,4,2));
    myCards.push_back(PowerPlantCards(15,2,4,3));
    myCards.push_back(PowerPlantCards(16,2,4,3));
    
    myCards.push_back(PowerPlantCards(17,1,2,2));
    myCards.push_back(PowerPlantCards(18,0,0,5));
    myCards.push_back(PowerPlantCards(19,2,4,3));
    myCards.push_back(PowerPlantCards(20,3,6,5));
    myCards.push_back(PowerPlantCards(21,2,4,4));
    myCards.push_back(PowerPlantCards(22,0,0,2));
    myCards.push_back(PowerPlantCards(23,1,2,3));
    
    myCards.push_back(PowerPlantCards(24,2,4,4));
    myCards.push_back(PowerPlantCards(25,2,4,5));
    myCards.push_back(PowerPlantCards(26,2,4,5));
    myCards.push_back(PowerPlantCards(27,0,0,3));
    myCards.push_back(PowerPlantCards(28,1,2,4));
    myCards.push_back(PowerPlantCards(29,1,2,4));
    myCards.push_back(PowerPlantCards(30,3,6,6));
    
    myCards.push_back(PowerPlantCards(31,3,6,6));
    myCards.push_back(PowerPlantCards(32,3,6,6));
    myCards.push_back(PowerPlantCards(33,0,0,4));
    myCards.push_back(PowerPlantCards(34,1,2,5));
    myCards.push_back(PowerPlantCards(35,1,2,5));
    myCards.push_back(PowerPlantCards(36,3,6,7));
    myCards.push_back(PowerPlantCards(37,0,0,4));
    
    myCards.push_back(PowerPlantCards(38,3,6,7));
    myCards.push_back(PowerPlantCards(39,1,2,6));
    myCards.push_back(PowerPlantCards(40,2,4,6));
    myCards.push_back(PowerPlantCards(42,2,4,6));
    myCards.push_back(PowerPlantCards(44,0,0,5));
    myCards.push_back(PowerPlantCards(46,3,6,7));
    myCards.push_back(PowerPlantCards(50,0,0,6));
    // highest card value
    
    return myCards;
}

// method to prints the PowerPlantCards
void PowerPlantCards::printPPCards(vector<PowerPlantCards>vector)
{
    for (int i = 0; i < vector.size(); i++) {
         std::cout << vector[i] << std::endl;
    }
}

// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const PowerPlantCards& card)
{
    outs << "Card Value: " << card.getCardValue() << "\t\t Number of Resources: " << card.getNumbResource()
    << "\t\t Max Resource Capacity: " << card.getCapacity() << "\t\t PowerHouse: " << card.getPowerHouse();
    
    // if the resource size > 0
    // print out the resource name and its cost
    return outs;
}
