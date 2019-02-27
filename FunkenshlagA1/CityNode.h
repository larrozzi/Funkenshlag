#pragma once

#include <map> 
#include <memory>
#include <vector>
#include "Resource.h"
using namespace std;


class CityNode
{
	private:
		string name;
		map<string,bool> ownedBy;
		bool used;
		vector<int> edges;
		Resource cost[] = new Resource[5];
	public:
		//constructors
		CityNode();
		CityNode(string n,bool u, vector<int> e, Resource c[]);
		CityNode(string n, map<string, bool> o, bool u, vector<int> e);
		
		//getters
		string getName();
		map<string,bool> getOwners();
		bool getUsed();
		vector<string> getEdges();
		vector<Resource> getCost();
		
		//setters
		void setName(string n);
		void setOwners(map<string,bool> o);
		void use();
		void unUse();
		void setEdges(vector<string> e);
		void setCost(vector<Resource> c);
};
