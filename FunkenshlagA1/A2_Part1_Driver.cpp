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

static HouseColor convert(const std::string& clr)
{
    if (clr == "NO_COLOR")        return NO_COLOR;
    else if (clr == "RED")        return RED;
    else if (clr == "BLUE")        return BLUE;
    else if (clr == "GREEN")    return GREEN;
    else if (clr == "YELLOW")    return YELLOW;
    else if (clr == "BLACK")    return BLACK;
    else if (clr == "PINK")        return PINK;
    else return NO_COLOR;
}

int main()
{
    string name;
    string color;
    HouseColor clr;
    string cityName;
    SummaryCards overviewCard;
    int NumofPlayers;
    bool alreadyPickedClr = false;
    
     vector<shared_ptr<Player>> players;
    
    MapLoader mapLoader = MapLoader();
	string input;
	cout << "select map" << endl;
	cin >> input;
	GameMap gameMap = GameMap(mapLoader.readMap(input));

   // GameMap gameMap = GameMap(mapLoader.readMap("map.txt"));

    cout << "Hello and Welcome to Powergrid\n\n";
    gameMap.showMap();
    
        cout << "Enter the Number of Players\n" << "> ";
        cin >> NumofPlayers;
    
        while (NumofPlayers < 2 || NumofPlayers > 6) {
            cout << "Number of players should be between 2 and 6." << endl;
            cout << "Enter the Number of Players\n" << "> ";
            cin >> NumofPlayers;
        }
    
                ///configuring the players one by one
        for (int i = 0; i < NumofPlayers; ++i) {
                ///creating a Player
            cout << "" << endl;
            cout << "Please enter your name  \n";
            cout << "> ";
            cin >> name;
            cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
            cout << "> ";
            cin >> color;
            clr = convert(color);
    
            for (int i = 0; i < players.size(); i++) {
                if (players.at(i)->getColor() == clr) {
                    alreadyPickedClr = true;
                }
            }
            while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK")|| alreadyPickedClr) {
                cout << "Please pick a valid color (either you entered an invalid color or the color was already picked by another player)." << endl;
                cout << "Please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
                cout << "> ";
                cin >> color;
                clr = convert(color);
                for (int i = 0; i < players.size(); i++) {
                    if (players.at(i)->getColor() == clr) {
                        alreadyPickedClr = true;
                    }
                    else
                        alreadyPickedClr = false;
                }
            }
    
                ///initializing a Player
            players.push_back(std::make_shared<Player>(name, 50, clr));
                /// taking 22 house items
            players.at(i)->grabhouses();
                /// taking an overview card
            cout << overviewCard;
            
            gameMap.chooseRegion();
        }
    

    system("pause");
    return 0;
    
}
