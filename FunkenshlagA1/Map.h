#pragma once

#include "House.h"
#include <map> 
#include "PowerPlantCard.h"
#include "Resource.h"
#include "ResourceMarket.h"
#include <memory>
#include <vector>

using namespace std;


class Map 
{
private:

	vector<CityNode> map;

public:
	//constructors
	Map();
	Map(vector<CityNode> m);

	//getters

	vector<CityNode> getMap();


};