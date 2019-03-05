//#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>    //library to split strings
#include "GameMap.h"
#include "MapLoader.h"
#include "CityNode.h"
#include "GameMap.h"
#include <sstream>
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

vector<CityNode> MapLoader::readMap(string f)
{
	fileName = f;
	vector<CityNode> result = exec();
	return result;
}

// where all the magic happens
vector<CityNode> MapLoader::exec()
{
	string cityString;
	string edgesString;
	string costString;
	vector<string> edgesVector;
	vector<string> costVector;
	vector<CityNode> cities(100);
	int i = 0;
	bool used = true;
	string line;
	string segment;
	ifstream myfile(this->fileName);
	vector<int> costVectorInt;
	vector<string> lineVariables(3);

	if (myfile.is_open())
	{
	
		while (getline(myfile, line))	//takes a whole line
		{
			std::istringstream input;
			input.str(line);
			while (getline(input, segment,'|'))	//seperates line into segments divided by '|'
			{
				lineVariables.push_back(segment);
			}
			cityString = lineVariables.at(0);
			edgesString = lineVariables.at(1);
			costString = lineVariables.at(2);

			boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesstring into vector delimiter: ','
			boost::split(costVector, costString, [](char c) {return c == ','; });    // split coststring into vector delimiter: ','
			cities[i].setValues(cityString, edgesVector, costVector);
		}
		myfile.close();
	}
		else cout << "Incorrect file format";
		return cities;
}