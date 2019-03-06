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
	string cityString;
	string edgesString;
	string costString;
	vector<string> edgesVector;
	vector<string> costVector;
	vector<CityNode> cities(100);
	int i = 0;
	bool used = true;
	string line;
	ifstream myfile(this->fileName);
	vector<int> costVectorInt;
	vector<string> lineVariables(3);

	if (myfile.is_open())
	{
	
		// -------------segment added by yassine. still need improvment
		for (unsigned n = 0; n <= 2; n++) {
			for (unsigned i = 0; i < lineVariables.size(); i++) {

				(getline(myfile, line, '|'));
				lineVariables.at(i) = line;
				cityString = lineVariables.at(0);
				edgesString = lineVariables.at(1);
				costString = lineVariables.at(2);

			}
			cout << cityString << "|" << edgesString << "|" << costString << "\n";    // read line of file
		}
			/*for (vector<string>::const_iterator i = lineVariables.begin(); i != lineVariables.end(); ++i)
						cout << *i << ' ';*/
		
		myfile.close();
		//----------------------------



		//while (getline(myfile, line))
		//{
		//	cout << cityString << "|" << edgesString << "|" << costString << "\n";    // read line of file

		//	boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesString into vector delimiter: ','
		//	boost::split(costVector, costString, [](char c) {return c == ','; });    // split costString into vector delimiter: ','

		//	//for (int j = 0; j < costVector.size(); j++)
		//	//{
		//	//	int t = stoi(costVector[j]);
		//	//	costVectorInt.push_back(t);
		//	//}

		//	//ALGORITHM TO ASSIGN VARIABLES
		//	cities.push_back.setValues(cityString, edgesVector, costVector);
		//	i++;
		//}

		//myfile.close();
	}
		else cout << "Incorrect file format";
		return cities;
}