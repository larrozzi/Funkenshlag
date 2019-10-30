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
    cardInfo = "1. DETERMINE TURN ORDER \n2. BUY POWER PLANT \n\t The first player begins. \n\t Per round, each may buy only one power plant. \n3. BUY RAW MATERIALS \n\t The last player begins. \n\t Maximum double input per power plant. \n4. BUILDING \n\t The last player begins. \n5. BUREAUCRACY \n\t-Get money. \n\t-In phase 1 and 2: Place highest power plant under the stack. \n\t-In phase 3: Remove lowest power plant from the game. \n\t-Restock raw materials.";
}

SummaryCards::SummaryCards(Player owner) : owner(owner) {
	cardInfo = "1. DETERMINE TURN ORDER \n2. BUY POWER PLANT \n\t The first player begins. \n\t Per round, each may buy only one power plant. \n3. BUY RAW MATERIALS \n\t The last player begins. \n\t Maximum double input per power plant. \n4. BUILDING \n\t The last player begins. \n5. BUREAUCRACY \n\t-Get money. \n\t-In phase 1 and 2: Place highest power plant under the stack. \n\t-In phase 3: Remove lowest power plant from the game. \n\t-Restock raw materials.";
}

//SummaryCards::SummaryCards(Player owner, std::string cardInfo) : owner(owner), cardInfo(cardInfo) { /*NOTHING*/ }

// destructor
SummaryCards::~SummaryCards() {}

// setters
//void SummaryCards::setOwner(Player owner) { this->owner = owner; }
void SummaryCards::setCardInfo(std::string cardInfo) { this->cardInfo = cardInfo; }

// getters
//inline Player SummaryCards::getOwner() const { return owner; }
inline std::string SummaryCards::getCardInfo() const { return cardInfo; }

// method to create the SummaryCards
//vector<SummaryCards>SummaryCards::createSummaryCards(Player owner)
vector<SummaryCards>SummaryCards::createSummaryCards()
{
	vector<SummaryCards>mySumCards;
    mySumCards.push_back(SummaryCards());

	//mySumCards.push_back(SummaryCards(owner));
	/*
	mySumCards.push_back(SummaryCards("Player 1"));
	mySumCards.push_back(SummaryCards("Player 2"));
	mySumCards.push_back(SummaryCards("Player 3"));
	mySumCards.push_back(SummaryCards("Player 4"));
	mySumCards.push_back(SummaryCards("Player 5"));
	mySumCards.push_back(SummaryCards("Player 6"));
	 */

	return mySumCards;
}

// method to prints the SummaryCards
void SummaryCards::printSummaryCards(vector<SummaryCards>sCards)
{
	std::vector<SummaryCards>::iterator show; // create a vector iterator
	for (show = sCards.begin(); show != sCards.end(); show++) {
		std::cout << *show << std::endl;
	}
}

// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const SummaryCards& card)
{
	//outs << card.owner << "\n\nSummaryCard Information: \n" << card.cardInfo << std::endl;
    outs << "SummaryCard Information: \n" << card.cardInfo << std::endl;

	return outs;
}
