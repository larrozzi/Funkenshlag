////
////  main.cpp
////  COMP345A1
////
////  Created by Alek Faruq Aliu on 2019-02-08.
////  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
////
//
//#include <iostream>  // std::cout
//#include <ctime>     // std::time
//#include <cstdlib>   // std::rand, std::srand
//#include <algorithm> // std::random_shuffle
//#include "Cards.h"
//#include "SummaryCards.h"
//#include "PowerPlantCards.h"
//#include "Step3Card.h"
//using std::vector;
//
//// function prototypes
//int myrandom (int i); // random generator function
//void Shuffle(vector<PowerPlantCards>&cards); // shuffle method
//
//
//int main()
//{
//    /*** Testing methods ***/
//    
//    // Creating the PowerPlantCards
//    std::cout << "Creating PowerPlantCards:\n";
//    vector<PowerPlantCards> myV;
//    std::cout << "UnShuffled PowerPlantCards:" << std::endl;
//    myV = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
//    PowerPlantCards::printPPCards(myV);    // prints the PowerPlantCards info
//    
//    // Shuffles the PowerPlantCards
//    Shuffle(myV);
//    std::cout << "\nShuffled PowerPlantCards:" << std::endl;
//    PowerPlantCards::printPPCards(myV);
//    std::cout << "==============================================================================================================================================" << std::endl;
//    
//    // Creating Step3Card
//    std::cout << "\nCreating Step3Card:\n";
//    Step3Card step3;
//    std::cout << step3 << std::endl;
//    std::cout << "==============================================================================================================================================" << std::endl;
//
//    // Creating the SummaryCards
//    std::cout << "\nCreating SummaryCards for the Player: " << std::endl;
//    vector<SummaryCards> sum;
//    sum = SummaryCards::createSummaryCards(); // holds the created SummaryCards
//    //sum = SummaryCards::createSummaryCards(*p1); // holds the created SummaryCards
//    SummaryCards::printSummaryCards(sum); // print the SummaryCards info
//    
//    system("pause");
//    return 0;
//}
//
//// random generator function
//int myrandom (int i) {
//    return std::rand()%i;
//}
// // This method shuffles the PowerPlantCards
//void Shuffle(vector<PowerPlantCards>&cards) {
//     std::srand(unsigned (std::time(0)));
//     std::random_shuffle(cards.begin(), cards.end(), myrandom);
//}
