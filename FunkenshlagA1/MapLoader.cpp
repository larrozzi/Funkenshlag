#include <boost/algorithm/string.hpp>	//library to split strings
#include "Map.h"
#include "MapLoader.h"
#include "CityNode.h"
#include <iostream>
#include <fstream>
#include <map> 
#include <memory>
#include <vector>

using namespace std;

//constructors
MapLoader::MapLoader()
{}

MapLoader::MapLoader(string f)
{
	fileName = f;
	exec();
}

void MapLoader::readMap(string f)
{
	fileName = f;
	exec();
}

void MapLoader::exec()
{
	string cityString;
	string edgesString;
	string costString;
	std::vector<std::string> edgesVector;
	std::vector<std::string> costVector;
	std::vector<CityNode> cities;
	int i = 0;
	bool used = true;

	ifstream myfile(this.fileName);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << cityString << "|" << edgesString << "|" << costString << "\n";	// read line of file

			boost::split(edgesVector, edgesString, [](char c) {return c == ','; });	//split edgesString into vector delimiter: ','
			boost::split(costVector, costString, [](char c) {return c == ','; });	// split costString into vector delimiter: ','

			//ALGORITHM TO ASSIGN VARIABLES
			cities[i].(cityString, used, edgesVector, costVector);
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}