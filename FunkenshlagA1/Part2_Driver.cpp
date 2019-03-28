//#include <fstream>
//#include <iostream>
//#include <string>
//#include <map>
//#include <memory>
//#include <vector>
//#include "Player.h"
//#include "CityNode.h"
//#include "GameMap.h"
//#include "MapLoader.h"
//#include "SummaryCards.h"
//
//int main()
//{
//    MapLoader mapLoader = MapLoader();
//
//    GameMap gameMap = GameMap(mapLoader.readMap("map.txt"));
//
//    /*for (CityNode x : gameMap.getMap())
//    {
//        vector<string> eT = x.getEdges();
//        vector<string> cT = x.getCosts();
//        cout << x.getName() + '|';
//        for (string i : x.getEdges())
//        {
//            cout << i + ',';
//        }
//        cout << '|';
//        for (int i = 0; i < eT.size(); i++)
//        {
//            cout << cT[i] + ',';
//        }
//        cout << endl;
//    }*/
//
//    gameMap.chooseRegion();
//    system("pause");
//    return 0;
//}
