#pragma once

#include <iostream>
#include <map> 
#include <memory>
#include <vector>
#include "GameMap.h"
using namespace std;

class MapLoader
{
private:
	bool valid;		//checks for map validity
	string fileName;	//name of the map file
	vector<CityNode> exec();	//creates and reads a map with fileName
public:
	MapLoader();	//default constructor
	MapLoader(string f);	//constructor takes fileName

    string getFileName() const;
	vector<CityNode> readMap(string f);	// sets fileName
};
