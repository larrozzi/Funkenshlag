#pragma once
#include "Resource.h"
#include "Market.h"
#include "PowerPlantCards.h"


class ResourceManager {
private:
	const int MAX_RESOURCES;
	//Current number of the resource left available in stock.
	int numOfCoal;
	int numOfOil;
	int numOfGarbage;
	int numOfUranium;
public:
	ResourceManager();
	int getNumOfCoal();
	int getNumOfOil();
	int getNumOfGarbage();
	int getNumOfUranium();
	//Fills the Resource Market based on the rules.
	bool fillResourceMarket(int numOfPlayers, int step, Market<Resource>& market);
	//Fills the PowerPlants Market based on the rules.
	bool fillPowerMarket(int numOfPlayers, int step, Market<PowerPlantCards>& market);
};
