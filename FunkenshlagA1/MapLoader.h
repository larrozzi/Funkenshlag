#pragma once

#include <iostream>
#include <map> 
#include <memory>
#include <vector>

class MapLoader 
{
	private:
		bool valid;		//checks for map validity
		string fileName;	//name of the map file
		Map map;	//map object that needs to be filled with a vector<cityNode>
		void exec();	//creates and reads a map with fileName
	public:
		MapLoader();	//default constructor
		MapLoader(string f);	//constructor takes fileName

		void readMap(string f);	// sets fileName
};