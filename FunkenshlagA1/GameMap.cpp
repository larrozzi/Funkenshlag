#include "CityNode.h"
#include "GameMap.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <vector>

using namespace std;

vector<CityNode> activeMap(28);
// constructor
GameMap::GameMap() {}
GameMap::GameMap(vector<CityNode> m) : gameMap(m) {}

// getter/setter
vector<CityNode> GameMap::getMap() const
{
	return gameMap;
}
vector<CityNode> GameMap::getActiveMap() const
{
	return activeMap;
}
void GameMap::setMap(vector<CityNode> cities)
{
	gameMap = cities;
}
void GameMap::chooseRegion()
{
	int input;
	cout << "Please choose your region" << input;

	for (int i = (input*7);i < (input +7); i++)
	{
		gameMap.at(i).use(); //activates the cities
	}	

	for (CityNode c : gameMap)
	{
		if (c.getUsed == true)
		{
			activeMap.push_back(c);
		}
	}
}
//void GameMap::readMap()
//{
	//for (CityNode i: gameMap)
	//{
	//	string name = i.getName;
	//	cout << name + "|";
	//}
//}