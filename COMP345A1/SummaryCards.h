//
//  SummaryCards.h
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
#include "Cards.h"

class SummaryCards : public Cards
{
    private:
        std::string name;
    
    public:
        SummaryCards();
        ~SummaryCards();
    
    // setters/ getters
    void setName(std::string name);
    std::string getName();
    
};
