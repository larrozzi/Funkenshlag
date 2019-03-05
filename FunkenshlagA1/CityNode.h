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
	map<string,bool> ownedBy;
	bool used;
	vector<string> edges;
	vector<string> cost;

public:
	//constructors
	CityNode();
	CityNode(string n, bool u, vector<string> e, vector<string> c);
	CityNode(string n, map<string, bool> o, bool u, vector<string> e, vector<string> c);

	//getters
	string getName() const;
	map<string, bool> getOwners() const;
	bool getUsed() const;
	vector<string> getEdges() const;

	//setters
	void setName(string n);
	void setOwners(map<string, bool> o);
	void use();
	void unUse();
	void setEdges(vector<string> e);
	void setCosts(vector<string> c);
	void setValues(string n, vector<string> e, vector<string> c);

};