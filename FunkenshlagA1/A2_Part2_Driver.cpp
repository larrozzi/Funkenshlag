//////  COMP345A1
//////
//////  Created by Yassine Laaroussi 2019-02-08.
//////  Updated 2019-03-06

#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include "Player.h"
#include "SummaryCards.h"
#include "House.h"
#include "PPmarket.h"


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
	vector<Player*> players; //vector to use for player order

	cout << "Hello and Welcome to Powergrid\n\n";
	cout<< "Enter the Number of Players\n\n";
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
		//cout << *PL << "\n\n";  //  cant be refered to outside a scope??
	for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i) {
		cout << *i << "\n\n";
		//cout << *players.at(*i) << "\n\n";
	}

	// taking an overview card
	for (int i = 0; i < NumofPlayers; i++) {
		 overviewCard = SummaryCards(*players.at(i));
		cout << overviewCard;
	}

	//Auction time
	Player highestbidder;
	

	vector<PowerPlantCards> PPdeck = PowerPlantCards::createPowerPlantCards();// holds the created PowerPlantCards
	vector<PowerPlantCards> *ptrPPdeck = &PPdeck; // creating a pointer to point to the plants in the vector

	PPmarket *ppmarket = new PPmarket(); //creating a PP market to show the visible first 8 plants to players

	ppmarket->SetMPlants(&PPdeck); // initializing the PPmarket vector pointer PPlants to point to the powerplants created by createPowerPlantCards() method
	
	


	//ppmarket->SetMPlants(make_shared<vector<PowerPlantCards>>(PPdeck));

	// printing the PPmarket


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
	delete ppmarket;
	//delete PL;// replace by shared pointers possible
	return 0;
}
