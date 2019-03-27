#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "CityNode.h"
#include "Resource.h"
#include <map>
#include "Player.h"

using namespace std;



CityNode::CityNode()
{}

CityNode::CityNode(string n, bool u, vector<string> e, vector<string> c)
: name{ n }, used{ u }, edges{ e }, cost{ c }
{
}

CityNode::CityNode(string n, map<string, bool>  o, bool u, vector<string> e, vector<string> c)
: name{ n }, ownedBy{ o }, used{ u }, edges{ e },  cost{ c }
{}

CityNode::~CityNode()
{
    // delete each House pointer
    for(auto h : houses)
    delete h;
}

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
    return used;
}
vector<string> CityNode::getEdges() const
{
    return edges;
}

vector<string> CityNode::getCosts() const
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

void CityNode::setCosts(vector<string> c)
{
    cost = c;
}
void CityNode::setValues(string n, vector<string> e, vector<string> c)
{
    name = n;
    edges = e;
    cost = c;
}

// methods
vector<House*>CityNode::getHouses()
{
    return houses;
}

// returns the number of houses
int CityNode::getNumberOfHouses() const {
    return houses.size();
}

// House price based on number of house
int CityNode::getHousePrice() const
{
    switch (houses.size()) {
        case 0:
            return firstHousePrice;
        case 1:
            return secondHousePrice;
        case 2:
            return thirdHousePrice;
        default:
            return 0;
    }
}

bool CityNode::isFull() const
{
    return houses.size() == MAX_HOUSES;
}

bool CityNode::isConnected(string cityName)
{
//    for(auto connected = cityName.begin(); connected != connections.end(); ++connected)
//        if ((*connected)->getFirst()->getName() == cityName || (*connected)->getSec()->getName() == cityName)
//            return true;
    
    return false;
}

bool CityNode::addHouse(House* house)
{
    if(houses.size() == MAX_HOUSES) // if max, cannot add more houses
        return false;
    
    houses.push_back(house); // add to house vector
    return true;
}

// operator assignment overlaoding
// members
bool CityNode::operator==(const CityNode& city) { return this->name == city.name; }

bool CityNode::operator==(const string& cityName) { return this->name == cityName; }

// friends
bool operator==(const shared_ptr<CityNode>& first, const shared_ptr<CityNode>&sec) {
    return first->name == sec->name;
}

bool operator==(const shared_ptr<CityNode>& first, const CityNode& city) {
    return first->name == city.name;
}

bool operator==(const shared_ptr<CityNode>& city, const string & cityName) {
    return city->name == cityName;
}
