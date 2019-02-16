//
//  main.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include "Cards.h"
#include "SummaryCards.h"
#include "PowerPlantCards.h"
#include "Step3Card.h"

using std::vector;

// method prototypes
// void Shuffle(); // prototype of shuffle method
vector<PowerPlantCards>createPowerPlantCards();
// void printCards(vector<PowerPlantCards>cards);


int main()
{
    // Testing methods
    
    vector<PowerPlantCards>myV;
    // holds the card vector
    myV = PowerPlantCards::createPowerPlantCards();
    
    // prints the card info
    PowerPlantCards::printPPCards(myV);
    
    vector<SummaryCards> sum;
    sum = SummaryCards::createSummaryCards();
    SummaryCards::printSummaryCards(sum);
    
    return 0;
}

/*
 // method that shuffles the cards
 void Shuffle()
 {
 
 }
 */


