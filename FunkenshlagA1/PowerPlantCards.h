 //
//  PowerPlantCards.h
//  COMP345A1
//
//  Created by Alek Faruq Aliu on 2019-02-08.
//  Copyright © 2019 Adelekan Faruq Aliu. All rights reserved.
//

#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Cards.h"
#include "Resource.h"
using std::vector;

//enum ResourceType { COAL, OIL, HYBRID, GARBAGE, URANIUM, ECOFUSION };

class PowerPlantCards : public Cards
{
private:
	int cardValue;  // the min bid of the power plant
	Type resourceType; // the recourceType of the power plant
	int numbResource; // how many number of resources the card needs
	int capacity;   // how many resources can be taken => 2* #resource
	int powerHouse; // how many houses can be powered

	

	//ResourceType resourceType;
	//std::vector<ResourceType> activeResource; // what is the active resource

public:
	//vector<PowerPlantCards>myCards;

	PowerPlantCards();
	PowerPlantCards(int cardValue, Type resourceType, int numbResource, int capacity, int powerHouse);
	~PowerPlantCards();

	// setters
	void setCardValue(int cardValue);
	void setResourceType(Type resourceType);
	void setResource(int numbResource);
	void setCapacity(int capacity);
	void setPowerHouse(int powerHouse);

	// getters
    int getCardValue() const;
	Type getResourceType() const;
	int getNumbResource() const;
	int getCapacity() const;
	int getPowerHouse() const;

	// methods declaration
	static vector<PowerPlantCards>createPowerPlantCards();
	static void printPPCards(vector<PowerPlantCards>vector);

	// overloading the output operator
	
	friend std::ostream& operator<<(std::ostream& outs, const PowerPlantCards& card);
};


