//
//  SummaryCards.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "SummaryCards.h"

using std::vector;

// constructors
SummaryCards::SummaryCards() {
    cardInfo = "1. DETERMINE TURN ORDER \n2. BUY POWER PLANT \n The first player begins. \n Per round, each may buy only one power plant. \n3. BUY RAW MATERIALS \n The last player begins. \n Maximum double input per power plant. \n4. BUILDING \n The last player begins. \n5. BUREAUCRACY \n -Get money. \n -In phase 1 and 2: Place highest power plant under the stack. \n -In phase 3: Remove lowest power plant from the game. \n -Restock raw materials.";
}
SummaryCards::SummaryCards(std::string name, std::string cardInfo) : name(name), cardInfo(cardInfo) { /*NOTHING*/ }

// destructor
SummaryCards::~SummaryCards() {}

// setters
void SummaryCards::setName(std::string name) { this->name = name; }
void SummaryCards::setCardInfo(std::string cardInfo) { this->cardInfo = cardInfo; }

// getters
inline std::string SummaryCards::getName() const { return name; }
inline std::string SummaryCards::getCardInfo() const { return cardInfo; }

// method to create the SummaryCards
vector<SummaryCards>SummaryCards::createSummaryCards()
{
    vector<SummaryCards>mySumCards;
    
    mySumCards.push_back(SummaryCards());
    mySumCards.push_back(SummaryCards());
    mySumCards.push_back(SummaryCards());
    mySumCards.push_back(SummaryCards());
    mySumCards.push_back(SummaryCards());
    mySumCards.push_back(SummaryCards());
    
    return mySumCards;
}

// method to prints the SummaryCards
void SummaryCards::printSummaryCards(vector<SummaryCards>vector)
{
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << std::endl;
    }
}

// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const SummaryCards& card)
{
    outs << "Card Name: " << card.name << "Card Information: \n" << card.cardInfo;
    return outs;
}
