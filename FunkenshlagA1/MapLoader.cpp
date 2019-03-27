//#include <bits/stdc++.h>
//#include <boost/algorithm/string.hpp>    //library to split strings
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
    string cityString = "hi";    // city name
    string edgesString;    //whole string with multiple edges
    string costString;    //whole string with multiple costs
    string line;    // individual line
    string segment;
    string edge;    //individual edge
    string cost;    //individual cost
    string edgesVector[100];
    string costVector[100];
    
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    bool used = true;
    ifstream myfile(this->fileName);
    vector<int> costVectorInt;
    string lineVariables[3];
    vector<CityNode> cities(60);
    if (myfile.is_open())
    {
        
        while (getline(myfile, line))    //takes a whole line
        {
            count++;
            stringstream linestream;
            stringstream edgestream;
            stringstream coststream;
            
            
            linestream.str(line);
            
            //NO ERRORS
            while (getline(linestream, segment,'|'))    //seperates line into segments divided by '|'
            {
                lineVariables[j] = segment;    //pushes the segments into vector
                j++;
            }
            
            
            cityString = lineVariables[0];        //assign the vector variables to corresponding Strings
            edgesString = lineVariables[1];
            costString = lineVariables[2];
            
            //cout << cityString + '|'<< edgesString + '|' << costString << endl; //WORKS FINE
            edgestream.str(edgesString);            //convert edgesString to edgesstream to allow getline() use
            while (getline(edgestream, edge, ','))
            {
                edgesVector[k] = edge;    // each object in edgestream seperated by ',' is pushed into edgesVector
                //cout << edgesVector[k] + " ";
                k++;
            }
            
            //same stuff, but for cost
            coststream.str(costString);
            while (getline(coststream, cost, ','))
            {
                costVector[l] = cost;
                //cout << costVector[l] + " ";
                l++;
            }
            
            //cout << cityString + '|' << edgesVector[0] + ',' +  edgesVector[1] + ',' + edgesVector[2] + '|' << costVector[0] + ',' + costVector[1] + ',' + costVector[2] << endl;
            std::vector<string> eV(edgesVector, edgesVector + sizeof edgesVector / sizeof edgesVector[0]);
            std::vector<string> cV(costVector, costVector + sizeof costVector / sizeof costVector[0]);
            eV.resize(k);
            cV.resize(l);
            
            // if some elements are empty, or # of edges != # of costs
            if (cityString == "" || eV.empty() || cV.empty() || eV.size() != cV.size())
            {
                cout << "Incorrect Map File" << endl;
                system("pause");
            }
            cities[i].setValues(cityString, eV, cV);
            i++;
            cities.resize(count+1);
            j = 0;
            k = 0;
            l = 0;
        }
        myfile.close();
    }
    else cout << "Incorrect file format";
    
    return cities;
}

//boost::split(edgesVector, edgesString, [](char c) {return c == ','; });    //split edgesstring into vector delimiter: ','
//boost::split(costVector, costString, [](char c) {return c == ','; });    // split coststring into vector delimiter: ','
