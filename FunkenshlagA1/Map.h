#pragma once

#include "House.h"
#include <map> 
#include "PowerPlantCards.h"
#include "Resource.h"
#include "ResourceMarket.h"
#include "CityNode.h"
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

	//getter/ setter
	vector<CityNode> getMap() const;
	void setMap(vector<CityNode> cities);
};
