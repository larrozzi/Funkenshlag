#include CityNode.h
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "CityNode.h"

using namespace std;

CityNode::CityNode();

CityNode::CityNode()
{}

CityNode::CityNode(string n, map<string, bool> o, bool a, vector<int> e) 
	: name{ n }, ownedBy{ o }, bool{ a },edges{ e }
{}