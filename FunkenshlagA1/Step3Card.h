//
//  Step3Card.h
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
#include "Cards.h"


class Step3Card : public Cards
{
private:
	std::string step;

public:
	Step3Card();
	~Step3Card();

	// setter/getter
	void setStep3Card(std::string step);
	std::string getStep3Card() const;

	// overloading output stream operator for Step3Card
	friend std::ostream& operator<<(std::ostream& outs, const Step3Card& card);
};