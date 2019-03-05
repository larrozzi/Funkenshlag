//#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>    //library to split strings
#include "GameMap.h"
#include "MapLoader.h"
#include "CityNode.h"
#include "GameMap.h"
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
	vector<CityNode> cities;
	int i = 0;
	bool used = true;
	string line;
	ifstream myfile(this->fileName);
	vector<int> costVectorInt;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << cityString << "|" << edgesString << "|" << costString << "\n";    // read line of file

			boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesString into vector delimiter: ','
			boost::split(costVector, costString, [](char c) {return c == ','; });    // split costString into vector delimiter: ','

			for (int j = 0; j < costVector.size(); j++)
			{
				int t = stoi(costVector[j]);
				costVectorInt.push_back(t);
			}

			//ALGORITHM TO ASSIGN VARIABLES
			cities[i].setValues(cityString, edgesVector, costVectorInt);
			i++;
		}

		myfile.close();
	}
	else cout << "Incorrect file format";
	return cities;
}