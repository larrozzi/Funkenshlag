#include <fstream>
#include <iostream>
#include <string>
#include <map> 
#include <memory>
#include <vector>
#include "Player.h"
#include "CityNode.h"
#include "GameMap.h"
#include "MapLoader.h"
#include "SummaryCards.h"


int main()
{
	MapLoader mapLoader = MapLoader();

	GameMap gameMap = GameMap(mapLoader.readMap("map.txt"));

}