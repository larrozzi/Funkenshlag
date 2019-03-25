#pragma once

#include <map>
#include <memory>
#include <vector>
#include <string>
#include <array>
#include "Resource.h"
#include "Player.h"
#include "House.h"
#include "Edges.h"

using namespace std;


class CityNode
{
private:
    string name;
    map<string,bool> ownedBy;
    bool used;
    vector<string> edges;
    vector<string> cost;
    
    static const int MAX_HOUSES = 3;
    vector<House*> houses;
    int firstHousePrice = 10;
    int secondHousePrice = 15;
    int thirdHousePrice = 20;
    vector<Edges> connections;
    
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
    vector<string> getCosts() const;
    
    //setters
    void setName(string n);
    void setOwners(map<string, bool> o);
    void use();
    void unUse();
    void setEdges(vector<string> e);
    void setCosts(vector<string> c);
    void setValues(string n, vector<string> e, vector<string> c);
    
    // methods
    vector<House*> getHouses();
    unsigned long getNumberOfHouses() const;
    int getHousePrice() const;
    bool isFull() const;
    bool isConnected(string cityNames);
    bool addHouse(House* house);
    
    // operator overlaoding
    bool operator==(const CityNode& city);
    bool operator==(const string& cityName);
    friend bool operator==(const shared_ptr<CityNode>& first, const shared_ptr<CityNode>&sec);
    friend bool operator==(const shared_ptr<CityNode>& first, const CityNode& city);
    friend bool operator==(const shared_ptr<CityNode>& city, const string & cityName);

};
