#pragma once

#include "House.h"
#include <map> 
#include "PowerPlantCards.h"
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
		bool used;
		vector<int> edges;
	public:
		//constructors
		CityNode();
		CityNode(string n, map<string, bool> o, bool u, vector<int> e);
		
		//getters
		string getName();
		map<string,bool> getOwners();
		bool getUsed();
		vector<int> getEdges();
		
		//setters
		void setName(string n);
		void setOwners(map<string,bool> o);
		void use();
		void unUse();
		void setEdges(vector<int> e);
};
