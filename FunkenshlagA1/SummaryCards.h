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
#include <vector>
#include "Cards.h"

using std::vector;

class SummaryCards : public Cards
{
    private:
        std::string name;
        std::string cardInfo;
    
    public:
        SummaryCards();
        SummaryCards(std::string name, std::string cardInfo);
        ~SummaryCards();
    
    // setters
    void setName(std::string name);
    void setCardInfo(std::string cardInfo);
    // getters
    std::string getName() const;
    std::string getCardInfo() const;

    // methods
    static vector<SummaryCards>createSummaryCards();
    static void printSummaryCards(vector<SummaryCards>vector);
    
    // overloading the output operator
    friend std::ostream& operator << (std::ostream& outs, const SummaryCards& card);
};
