//  COMP345A1
//
//  Created by Yassine Laaroussi 2019-02-08.
//  Updated 2019-03-06
//

#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"
using namespace std;

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

	// taking an overview card
	SummaryCards overviewCard = SummaryCards(*PL1);
	cout << overviewCard;

	ofstream outfile("players.txt",ios_base::app);
	if (outfile.is_open()) {
	//	outfile << *PL1;
		outfile << overviewCard;
		outfile.close();
	}
	else cout << "cannot open the file ";

	delete PL1;
	system("pause");
	return 0;
}
