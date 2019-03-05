#include "CityNode.h"
#include "GameMap.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <vector>

using namespace std;

// constructor
GameMap::GameMap() {}
GameMap::GameMap(vector<CityNode> m) : gameMap(m) {}

// getter/setter
vector<CityNode> GameMap::getMap() const
{
	return gameMap;
}
void GameMap::setMap(vector<CityNode> cities)
{
	gameMap = cities;
}
void GameMap::readMap()
{
	for (CityNode i: gameMap)
	{
		string name = i.getName;
		cout << name + "|";
	}
}