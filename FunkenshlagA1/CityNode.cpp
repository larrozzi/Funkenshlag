#include "CityNode.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <string>
#include "Resource.h"
#include <map>


using namespace std;



CityNode::CityNode()
{}

CityNode::CityNode(string n, bool u, map<string, int> e)
	: name{ n }, used{ u }, edges{ e }
{
}

CityNode::CityNode(string n, map<string, bool> o, bool u, map<string, int> e)
	: name{ n }, ownedBy{ o }, used{ u }, edges{ e }
{}

string CityNode::getName() const
{
	return name;
}
map<string, bool> CityNode::getOwners() const
{
	return ownedBy;
}
bool CityNode::getUsed() const
{
	bool activated = false;// error prev
	return activated;
}
map<string, int> CityNode::getEdges() const
{
	return edges;
}

void CityNode::setName(string n)
{
	name = n;
}

void CityNode::setOwners(map<string, bool> o)
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
void CityNode::setEdges(map<string, int> e)
{
	edges = e;
}
