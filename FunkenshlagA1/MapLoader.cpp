//#include <bits/stdc++.h>
//#include <boost/algorithm/string.hpp>    //library to split strings
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

// where all the magic happens
void MapLoader::exec()
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
	vector<int> temp;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << cityString << "|" << edgesString << "|" << costString << "\n";    // read line of file

			boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesString into vector delimiter: ','
			boost::split(costVector, costString, [](char c) {return c == ','; });    // split costString into vector delimiter: ','

			for (string i :costVector)
			{
				int t = stoi(i);
				temp.push_back(t);
			}

			//ALGORITHM TO ASSIGN VARIABLES
			cities[i].setValues(cityString, edgesVector, temp);
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}