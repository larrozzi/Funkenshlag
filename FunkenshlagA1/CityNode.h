#pragma once

#include <map> 
#include <memory>
#include <vector>
#include <string>
#include "Resource.h"
using namespace std;


class CityNode
{
	private:
		string name;
		map<string,bool> ownedBy;
		bool used;
		vector<int> edges;
        Resource cost[];// = new Resource[5];
	public:
		//constructors
		CityNode();
		CityNode(string n,bool u, vector<int> e, Resource c[]);
		CityNode(string n, map<string, bool> o, bool u, vector<int> e);
		
		//getters
		string getName() const;
		map<string,bool> getOwners() const;
		bool getUsed() const;
		vector<string> getEdges() const;
		vector<Resource> getCost() const;
		
		//setters
		void setName(string n);
		void setOwners(map<string,bool> o);
		void use();
		void unUse();
		void setEdges(vector<string> e);
		void setCost(vector<Resource> c);
    
        CityNode& operator=(const CityNode& obj);

};
