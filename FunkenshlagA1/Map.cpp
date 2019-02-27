#include "CityNode.h"
#include "Map.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"

using namespace std;

Map::Map();

Map::Map()
{}
Map::Map(vector<cityNode> m)
	: map{ m }
{}
Map::getMap()
{
	return map;
}
Map::setMap(vector<CityNode> cities)
{
	map = cities;
}
