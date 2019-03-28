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
	int input = 0;
	do {

		cout << "Please choose your region" << endl;
		cin >> input;
		cout << "you chose " << input << endl;

		if (gameMap.at(input * 7).getUsed() == true)
		{
			cout << "Region already selected";
		}
	} while (gameMap.at(input * 7).getUsed() == true);


	for (int i = (input * 7); i < ((input*7) + 7); i++)
	{
		gameMap.at(i).use();
	}
	
	for (CityNode c : gameMap)
	{
		cout << c.getUsed() << endl;
		if (c.getUsed() == true)
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


vector<shared_ptr<Edges>> const & GameMap::getEdges() const { return edges; }

map<string, shared_ptr<CityNode>> const & GameMap::getCities() const { return myCities; }

// shortest path between two cities
int GameMap::getShortestPath(string initCity, string destCity)
{
    return 10;
}
// cost of shortest path between player city and destination city
int GameMap::getShortestPath(shared_ptr<Player> player, string destCity)
{
    // no houses
    if (player->grabhouses().size() == 0)
        return 0;
    
    // default: from initial house to destination
    int minCost = getShortestPath(player->grabhouses()[0].getCity()->getName(), destCity);
    
    // loop over the player houses
    for (int i = 1; i < player->grabhouses().size(); i++) {
        int pathCost = getShortestPath(player->grabhouses()[0].getCity()->getName(), destCity);
        if (pathCost > minCost) {
            minCost = pathCost;
        }
    }
    return minCost;
    
}

// displays the game map
void GameMap::showMap() const
{
    for (CityNode x : gameMap)
    {
        vector<string> eT = x.getEdges();
        vector<string> cT = x.getCosts();
        cout << x.getName() + '|';
        for (string i : x.getEdges())
        {
            cout << i + ',';
        }
        cout << '|';
        for (int i = 0; i < eT.size(); i++)
        {
            cout << cT[i] + ',';
        }
        cout << endl;
    }
}
