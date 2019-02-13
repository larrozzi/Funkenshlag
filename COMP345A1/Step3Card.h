//
//  Step3Card.h
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Cards.h"

class Step3Card : public Cards
{
private:
    int step;
    
public:
    Step3Card();
    ~Step3Card();
    
    // setter/getter
    void setStep3Card(int step);
    int getStep3Card() const;
};
