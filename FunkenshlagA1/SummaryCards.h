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
#include "Player.h"


using std::vector;

class SummaryCards : public Cards
{
    private:
        Player owner;
        std::string cardInfo;
    
    public:
        SummaryCards();
        SummaryCards(Player owner);
        //SummaryCards(Player owner, std::string cardInfo);
        ~SummaryCards();
    
    // setters
    void setOwner(Player owner);
    void setCardInfo(std::string cardInfo);
    // getters
    inline Player getOwner() const;
    inline std::string getCardInfo() const;

    // methods declaration
    static vector<SummaryCards> createSummaryCards(Player owner);
    static void printSummaryCards(vector<SummaryCards>vector);
    
    // overloading the output operator
    friend std::ostream& operator << (std::ostream& outs, const SummaryCards& card);
};
