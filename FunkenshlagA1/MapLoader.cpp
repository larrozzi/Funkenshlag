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
	vector<CityNode> result = exec();
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
	string cityString = "hi";	// city name
	string edgesString;	//whole string with multiple edges
	string costString;	//whole string with multiple costs
	string line;	// individual line
	string segment;
	string edge;	//individual edge
	string cost;	//individual cost
	vector<string> edgesVector;
	vector<string> costVector;
	vector<CityNode> cities(100);
	int i = 0;
	int j = 0;
	bool used = true;
	ifstream myfile(this->fileName);
	vector<int> costVectorInt;
	string lineVariables[3];

	if (myfile.is_open())
	{
	
		while (getline(myfile, line))	//takes a whole line
		{
			stringstream linestream;
			stringstream edgestream;
			stringstream coststream;
			

			linestream.str(line);

			//NO ERRORS
			while (getline(linestream, segment,'|'))	//seperates line into segments divided by '|'
			{
				lineVariables[j] = segment;	//pushes the segments into vector
				j++;
			}


			cityString = lineVariables[0];		//assign the vector variables to corresponding Strings
			edgesString = lineVariables[1];
			costString = lineVariables[2];

			cout << cityString + '|'<< edgesString + '|' << costString << endl; //WORKS FINE
			edgestream.str(edgesString);			//convert edgesString to edgesstream to allow getline() use
			while (getline(edgestream, edge, ','))
			{
				edgesVector.push_back(edge);	// each object in edgestream seperated by ',' is pushed into edgesVector
			}
			
				//same stuff, but for cost
			coststream.str(costString);
			while (getline(coststream, cost, ','))
			{
				costVector.push_back(cost);
			}

			cities[i].setValues(cityString, edgesVector, costVector);
			i++;
			j = 0;
		}
		myfile.close();
	}
		else cout << "Incorrect file format";

		return cities;
}

//boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesstring into vector delimiter: ','
//boost::split(costVector, costString, [](char c) {return c == ','; });    // split coststring into vector delimiter: ','