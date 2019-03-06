#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"

int main()
{
	string name;
	string color;
	HouseColor clr;
	string cityName;

	cout << "Hello and Welcome to Powergrid\n\n";
	cout << "Please enter your NAME \n";
	cin >> name;
	cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
	cin >> color;
	clr = convert(color);

	Player PL1 = Player(name, 50, clr);

	PL1.grabhouses();
	// enter one of the following cities to do

	cout << "Please enter the city you'd like to build a house in \n";
	cin >> cityName;
	PL1.buildinCity(cityName);
	//PL1.buildinCity("Rabat");


	SummaryCards overviewCard = SummaryCards(PL1);
	cout << overviewCard;

	//to append
	//std::ofstream outfile("players.txt", std::ios_base::app);

	ofstream outfile("players.txt");
	if (outfile.is_open()) {
		outfile << PL1;
		outfile << overviewCard;
		outfile.close();
	}
	else cout << "cannot open the file ";

	system("pause");
	return 0;
}
