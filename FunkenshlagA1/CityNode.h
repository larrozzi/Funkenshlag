#pragma once

#include <map> 
#include <memory>
#include <vector>
#include <string>
#include <array>
#include "Resource.h"
using namespace std;


class CityNode
{
	private:
		string name;
		map<string,bool> ownedBy;
		bool used;
		vector<int> edges;
        array<Resource,5> cost; // using C++ class array
	public:
		//constructors
		CityNode();
    CityNode(string n,bool u, vector<int> e, array<Resource,5> c);
		CityNode(string n, map<string, bool> o, bool u, vector<int> e);
		
		//getters
		string getName() const;
		map<string,bool> getOwners() const;
		bool getUsed() const;
		vector<int> getEdges() const;
		array<Resource,5> getCost() const;
		
		//setters
		void setName(string n);
		void setOwners(map<string,bool> o);
		void use();
		void unUse();
		void setEdges(vector<int> e);
		void setCost(array<Resource,5> c);
    
};
