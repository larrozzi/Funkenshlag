//
//  main.cpp
//  COMP345Ass1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved. 
//

// void Shuffle(); // prototype of shuffle method

#include <iostream>
#include "Cards.h"
#include "SummaryCards.h"
#include "PowerPlantCards.h"
#include "Step3Card.h"


int main()
{
    //int hello = 1;
    //std::cout << hello << std::endl;
    
    PowerPlantCards::createCards();
    PowerPlantCards::printCards();
    
    
    return 0;
}

/*
// method that shuffles the cards
void Shuffle()
{
    
}
*/
