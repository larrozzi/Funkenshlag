#include "CityNode.h"
#include "Map.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <vector>

using namespace std;

// constructor
Map::Map() {}
Map::Map(vector<CityNode> m) : map(m) {}

// getter/setter
vector<CityNode> Map::getMap() const
{
	return map;
}
void Map::setMap(vector<CityNode> cities)
{
	map = cities;
}