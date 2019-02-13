//
//  SummaryCards.cpp
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#include "SummaryCards.h"

// constructors
SummaryCards::SummaryCards() {}
SummaryCards::~SummaryCards() {}

// setter/getter
void SummaryCards::setName(std::string name) { this->name = name; }
inline std::string SummaryCards::getName() { return name; }

