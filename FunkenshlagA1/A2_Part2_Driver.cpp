//////  COMP345A1
//////
//////  Created by Yassine Laaroussi 2019-02-08.
//////  Updated 2019-03-06

#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"
#include "House.h"
using namespace std;
using std::cout;


static HouseColor convert(const std::string& clr)
{
	if (clr == "NO_COLOR")		return NO_COLOR;
	else if (clr == "RED")		return RED;
	else if (clr == "BLUE")		return BLUE;
	else if (clr == "GREEN")	return GREEN;
	else if (clr == "YELLOW")	return YELLOW;
	else if (clr == "BLACK")	return BLACK;
	else if (clr == "PINK")		return PINK;
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
	int fullturn;
	int phase = 1;
	//vector<shared_ptr<Player>> players;
	vector<Player*> players;
	cout << "Hello and Welcome to Powergrid\n\n";

	cout<< "Enter number of players\n\n";
	cin >> NumofPlayers;
	 
	for (int i = 0; i < NumofPlayers; i++) {
		//creating the Players

		cout << "Please enter the name of player \n"<<++i;
		cin >> name;
		cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
		cin >> color;
		clr = convert(color);

		//initializing a Player
		Player* PL = new Player(name, 50, clr);
		players.push_back(PL);

		// taking 22 houses
		PL->grabhouses();

		// Owning a city
		cout << "Please enter the city you'd like to build a house in \n";
		cin >> cityName;

		//PL->readFile();
		//PL->buildinCity(cityName);

	}
	//printing the player possessions
		//cout << *PL << "\n\n";  // why cant be refered to outside a scope??
	for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i) {
		cout << *i << "\n\n";
		//cout << *players.at(*i) << "\n\n";
	}

	// taking an overview card
	for (int i = 0; i < NumofPlayers; i++) {
		 overviewCard = SummaryCards(*players.at(i));
		cout << overviewCard;
	}
	

	ofstream outfile("players.txt",ios_base::app);
	for (int i = 0; i < NumofPlayers; i++) {
		if (outfile.is_open()) {
			outfile << *players.at(i);
			outfile << overviewCard;
			outfile.close();
		}
		else cout << "cannot open the file ";
	}

	
	system("pause");
	//delete PL;// replace by shared pointers
	return 0;
}
