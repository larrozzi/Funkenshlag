#pragma once

#include <map> 
#include <memory>
#include <vector>
#include <string>
#include <array>
#include "Resource.h"
#include "Player.h"
using namespace std;


class CityNode
{
private:
	string name;
	map<Player,bool> ownedBy;
	bool used;
	vector<string> edges;
	vector<int> cost;

public:
	//constructors
	CityNode();
	CityNode(string n, bool u, vector<string> e, vector<int> c);
	CityNode(string n, map<Player, bool> o, bool u, vector<string> e, vector<int> c);

	//getters
	string getName() const;
	map<Player, bool> getOwners() const;
	bool getUsed() const;
	vector<string> getEdges() const;

	//setters
	void setName(string n);
	void setOwners(map<Player, bool> o);
	void use();
	void unUse();
	void setEdges(vector<string> e);
	void setCosts(vector<int> c);
	void setValues(string n, vector<string> e, vector<int> c);

};