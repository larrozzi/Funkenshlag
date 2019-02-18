//
//  main.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>  // std::cout
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle
#include "Cards.h"
#include "SummaryCards.h"
#include "PowerPlantCards.h"
#include "Step3Card.h"

using std::vector;

// method prototypes
void Shuffle(vector<PowerPlantCards>&cards); // prototype of shuffle method

int main()
{
    // Testing methods
    vector<PowerPlantCards>myV;
    // holds the card vector
    std::cout << "UnShuffled PowerPlantCards:" << std::endl;
    myV = PowerPlantCards::createPowerPlantCards();
    // prints the card info
    PowerPlantCards::printPPCards(myV);
    
    // shuffles the cards
    Shuffle(myV);
    std::cout << "\nShuffled PowerPlantCards:" << std::endl;
    PowerPlantCards::printPPCards(myV);
    
    /*
    vector<SummaryCards> sum;
    sum = SummaryCards::createSummaryCards();
    SummaryCards::printSummaryCards(sum);
    */
    return 0;
}

 // method that shuffles the cards
 void Shuffle(vector<PowerPlantCards>&cards)
 {
     std::srand((unsigned)std::time(0));
     std::random_shuffle(cards.begin(), cards.end());
 }



