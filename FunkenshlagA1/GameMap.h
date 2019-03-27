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


class GameMap
{
private:

	vector<CityNode> gameMap;

public:
	//constructors
	GameMap();
	GameMap(vector<CityNode> m);

	//getter/ setter
	vector<CityNode> getMap() const;
	vector<CityNode> getActiveMap() const;
	void setMap(vector<CityNode> cities);
	//void readMap();
	void chooseRegion();
};
