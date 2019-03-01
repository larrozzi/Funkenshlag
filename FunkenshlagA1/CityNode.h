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
	map<string, bool> ownedBy;
	bool used;
	map<string, int> edges;

public:
	//constructors
	CityNode();
	CityNode(string n, bool u, map<string, int> e);
	CityNode(string n, map<string, bool> o, bool u, map<string, int> e);

	//getters
	string getName() const;
	map<string, bool> getOwners() const;
	bool getUsed() const;
	map<string, int> getEdges() const;

	//setters
	void setName(string n);
	void setOwners(map<string, bool> o);
	void use();
	void unUse();
	void setEdges(map<string, int> e);

};