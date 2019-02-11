#pragma once

#include "House.h"
#include <map> 
#include "PowerPlantCard.h"
#include "Resource.h"
#include "ResourceMarket.h"
#include <memory>
#include <vector>

using namespace std;


class CityNode
{
	private:
		string name;
		map<string,bool> ownedBy;
		bool activated;
		vector<int> edges;
	public:
		//constructors
		CityNode();
		CityNode(string n, map<string, bool> o, bool a, vector<int> e);
		
		//getters
		string getName();
		map<string,bool> getOwners();
		bool getActivated();
		vector<int> getEdges();
		
		//setters
		void setName(string n);
		void setOwners(map<string,bool> o);
		void activate();
		void deactivate();
		void setEdges(vector<int> e);
};
