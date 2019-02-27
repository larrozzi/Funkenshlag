

#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <map> 
#include <memory>
#include <vector>


using namespace std;

MapLoader::MapLoader()
{}

MapLoader::MapLoader(string f)
{
	string line
	ifstream myfile("fileName.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	
	else cout << "Unable to open file";
	return 0;
}
