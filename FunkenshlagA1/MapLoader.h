#pragma once

#include <iostream>
#include <map> 
#include <memory>
#include <vector>

class MapLoader 
{
	private:
		bool valid;

	public:
		MapLoader();
		MapLoader(string fileName);
};