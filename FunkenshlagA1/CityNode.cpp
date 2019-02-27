#include "CityNode.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"
#include <string>
#include "Resource.h"


using namespace std;



CityNode::CityNode()
{}

CityNode::CityNode(string n, bool u, vector<int> e, Resource c[])
    : name{ n }, used{ u }, edges{ e }, cost{ *c }
{}

CityNode::CityNode(string n, map<string, bool> o, bool u, vector<int> e) 
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
    bool activated=false;// error prev
    return activated;
}
vector<string> CityNode::getEdges() const
{
    return edges;
}

vector<Resource> CityNode::getCost() const
{
	return cost;
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
void CityNode::setEdges(vector<string> e)
{
    edges = e;
}

void CityNode::setCost(vector<Resource> c)
{
	cost = c;
}
