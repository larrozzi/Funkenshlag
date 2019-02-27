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

// function prototypes
int myrandom (int i); // random generator function
void Shuffle(vector<PowerPlantCards>&cards); // shuffle method


int main()
{
    /*** Testing methods ***/
    
    // Creating the PowerPlantCards
    vector<PowerPlantCards> myV;
    std::cout << "\nUnShuffled PowerPlantCards:" << std::endl;
    myV = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
    PowerPlantCards::printPPCards(myV);    // prints the PowerPlantCards info

    // Shuffles the PowerPlantCards
    Shuffle(myV);
    std::cout << "\nShuffled PowerPlantCards:" << std::endl;
    PowerPlantCards::printPPCards(myV);
    
    // Creating the SummaryCards
    std::cout << "\nSummaryCards: " << std::endl;
    vector<SummaryCards> sum;
    sum = SummaryCards::createSummaryCards(); // holds the create SummaryCards
    SummaryCards::printSummaryCards(sum); // print the SummaryCards info
    
    // Creating Step3Card
    Step3Card step3;
    std::cout << step3 << std::endl;
    
    return 0;
}

// random generator function
int myrandom (int i) {
    return std::rand()%i;
}
 // This method shuffles the PowerPlantCards
void Shuffle(vector<PowerPlantCards>&cards) {
     std::srand(unsigned (std::time(0)));
     std::random_shuffle(cards.begin(), cards.end(), myrandom);
}