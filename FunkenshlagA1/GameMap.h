#pragma once

#include "House.h"
#include <map> 
#include "PowerPlantCards.h"
#include "Resource.h"
#include "ResourceMarket.h"
#include "CityNode.h"
#include "Player.h"
#include <memory>
#include <vector>
#include "Edges.h"


using namespace std;


class GameMap
{
private:

	vector<CityNode> gameMap;
    vector<shared_ptr<Edges>> edges;
    map<string, shared_ptr<CityNode>> myCities;

public:
	//constructors
	GameMap();
	GameMap(vector<CityNode> m);

	//getter/ setter
	vector<CityNode> getMap() const;
	void setMap(vector<CityNode> cities);
    
	//void readMap();
    vector<shared_ptr<Edges>> const & getEdges() const;
    map<string, shared_ptr<CityNode>> const & getCities() const;
    int getShortestPath(string initCity, string destCity);
    int getShortestPath(shared_ptr<Player> player, string destCity);
    void showMap() const;
    
};
