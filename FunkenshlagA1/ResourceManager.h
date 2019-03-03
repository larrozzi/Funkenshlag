#pragma once
#include "Resource.h"
#include "ResourceMarket.h"
//#include "PowerPlantCards.h"


class ResourceManager {
private:
	const int MAX_RESOURCES = 24;
	const int MAX_URANIUM = 12;
	//Current number of the resource left available in stock.
	int numOfCoal;
	int numOfOil;
	int numOfGarbage;
	int numOfUranium;
	//2-D array of the different Resources placed in each Market slot.
	Resource marketCoal[8][3];
	Resource marketOil[8][3];
	Resource marketGarbage[8][3];
	Resource marketUranium[12][1];
public:
	ResourceManager();
	ResourceManager(ResourceMarket rMarket);
	bool setupMarket();
	int getNumOfCoal();
	int getNumOfOil();
	int getNumOfGarbage();
	int getNumOfUranium();
};