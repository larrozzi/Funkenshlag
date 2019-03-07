////  COMP345A1
////
////  Created by Yassine Laaroussi 2019-02-08.
////  Updated 2019-03-06

#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"
#include "House.h"
using namespace std;


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

	cout << "Hello and Welcome to Powergrid\n\n";

	//creating a Player
	cout << "Please enter your NAME \n";
	cin >> name;
	cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
	cin >> color;
	clr = convert(color);

	//initializing a Player
	Player* PL1 = new Player(name, 50, clr);

	// taking 22 houses
	PL1->grabhouses();

	// Owning a city
	cout << "Please enter the city you'd like to build a house in \n";
	cin >> cityName;

	PL1->readFile();
	PL1->buildinCity(cityName);

	//printing the player possessions
	cout << *PL1 << "\n\n";

	// taking an overview card
	SummaryCards overviewCard = SummaryCards(*PL1);
	cout << overviewCard;

	ofstream outfile("players.txt",ios_base::app);
	if (outfile.is_open()) {
		outfile << *PL1;
		outfile << overviewCard;
		outfile.close();
	}
	else cout << "cannot open the file ";

	
	system("pause");
	delete PL1;
	return 0;
}
