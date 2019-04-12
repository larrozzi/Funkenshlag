#include <iostream>
#include "ResourceMarket.h"
#include "GameTurnSubject.h"
#include "SummaryCards.h"
#include "GameFunctions.h"

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

int main() {
	int phase = 1;
	int step = 1;
	int numOfPlayers;
	string name;
	string color;
	HouseColor clr;
	bool alreadyPickedClr = false;
	vector<shared_ptr<Player>> players;
	SummaryCards overviewCard;
	GameFunctions* game;


	GameTurnSubject* gameTurn = new GameTurnSubject();
	ResourceMarket* market = new ResourceMarket();

	//INITIAL PLAYER SETUP
	std::cout << "Hello and Welcome to Powergrid\n\n";
	std::cout << "Enter the Number of Players\n" << "> ";
	std::cin >> numOfPlayers;
	
	while (numOfPlayers < 2 || numOfPlayers > 6) {
	    std::cout << "Number of players should be between 2 and 6." << std::endl;
	    std::cout << "Enter the Number of Players\n" << "> ";
	    std::cin >> numOfPlayers;
	}
	
	        ///configuring the players one by one
	for (int i = 0; i < numOfPlayers; ++i) {
	        ///creating a Player
	    std::cout << "" << std::endl;
	    std::cout << "Player " << i+1 <<", please enter your name  \n";
	    std::cout << "> ";
	    std::cin >> name;
	    std::cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
	    std::cout << "> ";
	    std::cin >> color;
	    clr = convert(color);
	
	    for (int i = 0; i < players.size(); i++) {
	        if (players.at(i)->getColor() == clr) {
	            alreadyPickedClr = true;
	        }
	    }
	    while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK")|| alreadyPickedClr) {
	        std::cout << "Please pick a valid color (either you entered an invalid color or the color was already picked by another player)." << std::endl;
	        std::cout << "Please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
	        std::cout << "> ";
	        std::cin >> color;
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
	    std::cout << overviewCard;
		
	}
	game = new GameFunctions(numOfPlayers, players);
	game->setupDeckCards();

	game->RandomPlayerOrder();

	game->AuctionTime(gameTurn);

	system("pause");
}

