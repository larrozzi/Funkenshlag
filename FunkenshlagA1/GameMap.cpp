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
void GameMap::chooseRegion()
{
	int input;

	cout << "Please choose your region" << input;

	switch (input)
	{
	case 0:
		for (int i = 0; i < 7; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;
	case 1:
		for (int i = 7; i < 14; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;
	case 2:
		for (int i = 14; i < 21; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;
	case 3:
		for (int i = 21; i < 28; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;
	case 4:
		for (int i = 28; i < 35; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;
	case 5:
		for (int i = 35; i < 42; i++)
		{
			gameMap.at(i).use(); //activates the cities
		}
		break;

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