#include "CityNode.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <string>
#include "Resource.h"
#include <map>
#include "Player.h"


using namespace std;



CityNode::CityNode()
{}

CityNode::CityNode(string n, bool u, vector<string> e, vector<int> c)
	: name{ n }, used{ u }, edges{ e }, cost{ c }
{
}

CityNode::CityNode(string n, map<Player*, bool>  o, bool u, vector<string> e, vector<int> c)
	: name{ n }, ownedBy{ o }, used{ u }, edges{ e },  cost{ c }
{}

string CityNode::getName() const
{
	return name;
}
map<Player*, bool> CityNode::getOwners() const
{
	return ownedBy;
}
bool CityNode::getUsed() const
{
	return used;
}
vector<string> CityNode::getEdges() const
{
	return edges;
}

void CityNode::setName(string n)
{
	name = n;
}

void CityNode::setOwners(map<Player*, bool> o)
{
	ownedBy = o;
}

void CityNode::use()
{
	used = true;
}
void CityNode::unUse()
{
	used = false;
}
void CityNode::setEdges(vector<string> e)
{
	edges = e;
}

void CityNode::setCosts(vector<int> c)
{
	cost = c;
}
void CityNode::setValues(string n, vector<string> e, vector<int> c)
{
	name = n;
	edges = e;
	cost = c;
}
