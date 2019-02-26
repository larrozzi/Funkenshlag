//
//  Step3Card.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include <iostream>
#include "Step3Card.h"

// constuctor
Step3Card::Step3Card() {
    step = "Step 3";
}
// destructor
Step3Card::~Step3Card() {}

// setter/getter
void Step3Card::setStep3Card(std::string step) { this->step = step; }
inline std::string Step3Card::getStep3Card() const { return step; }

// overloading output stream operator for Step3Card
std::ostream& operator<<(std::ostream& outs, const Step3Card& card)
{
    outs << "Card: " << card.step << std::endl;
    return outs;
}
