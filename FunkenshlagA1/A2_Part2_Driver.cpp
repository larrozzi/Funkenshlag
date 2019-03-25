//////  COMP345A1
//////
//////  Created by Yassine Laaroussi 2019-02-08.
//////  Updated 2019-03-06

#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <time.h> 
#include <vector>
#include <map>
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

	int turn = 0;
//	int fullturn; // after any player buying a pp
	int phase = 1;
	int PPindex;
	int playerbid;
	bool initialbid;
	int highestBid=3;
	string BidOrPass;
	vector<shared_ptr<Player>> players;
	shared_ptr<Player> currentPlayer;
	shared_ptr<Player>highestbidder;
	vector<shared_ptr<Player>> playerOrder;
	std::map<Player*, bool> canBid;
	std::map<Player*, bool> canBuy;


	cout << "Hello and Welcome to Powergrid\n\n";
	cout<< "Enter the Number of Players\n\n";
	cin >> NumofPlayers;

			///configuring the players one by one
	for (int i = 0; i < NumofPlayers; ++i) {
			///creating a Player
		cout << "Please enter your name  \n"; //<<++i why need this
		cin >> name;
		cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
		cin >> color;
		clr = convert(color);

			///initializing a Player
	//	Player* PL = new Player(name, 50, clr);
	//	players.push_back(PL);
		players.push_back(std::make_shared<Player>(name, 50, clr));
			/// taking 22 house items
		//PL->grabhouses();
		players.at(i)->grabhouses();

			/// taking an overview card
		
		cout << overviewCard;
		/*for (int i = 0; i < NumofPlayers; ++i) {
			overviewCard = SummaryCards(*players[i]);
			cout << overviewCard;
		}*/

		/*	 Owning a city 
		cout << "Please enter the city you'd like to build a house in \n";
		cin >> cityName;
		PL->readFile();
		PL->buildinCity(cityName);*/
	}

		///Auction time

	cout << "Phase I" << endl;
	cout << "Random Player order on first Auction" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Phase II" << endl;
	cout << "Let's the Auction begin" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	vector<PowerPlantCards> Pplants = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards

	PPmarket *ppmarket = new PPmarket(); //creating a PP market that will show the visible first 8 plants to players
	vector<shared_ptr<PowerPlantCards>> PPlantsSptr; //the market PPlants in this vector need to point to the plants created	
	
	 Pplants.size();

	for ( int i=0; i<42; ++i)
	PPlantsSptr.push_back(std::make_shared<PowerPlantCards>(Pplants[i])); //the powerplant market is now linked to the created pplants

	//shared_ptr<PowerPlantCards> sharedptr(new PowerPlantCards); //same as next two lines ?
	/*PowerPlantCards* pp = new PowerPlantCards;  each pp inside the Pplants
	std::vector<std::shared_ptr<PowerPlantCards>> PPlantsSptr;
	PPlantsSptr.emplace_back(pp);
	*/

	//fill a vector of pointers to the powerplants created already
	ppmarket->SetMPlants(PPlantsSptr);

	//make the market ready for auction, filling the visibleplants vector
	ppmarket->Setup();
	 
	// printing the PPmarket
	ppmarket->printPPmarket();  // test needed

		/// random Player Order before first Auction
	
		vector<int> rvec(NumofPlayers);
		for (int i = 0; i < NumofPlayers; ++i)
			rvec[i] = i;
		auto rng = std::default_random_engine{};
		shuffle(begin(rvec), end(rvec),rng);
		for (int i = 0; i < NumofPlayers; ++i) {
			playerOrder.push_back(players[rvec[i]]);
		}
	
	int nextPlayerTurn = turn+1;

	for (int round = 0; round < NumofPlayers; ++round) {  //  rounds necessary for each player to win a powerplant
		initialbid = true;
		//for (int turn = 0; turn < NumofPlayers; turn++) { // number of turns to purchase one pp

			while (playerOrder[nextPlayerTurn] != currentPlayer){
				// Set current player by order
				currentPlayer = playerOrder[turn]; //player order inside a round
				
				//current player auction
			cout << currentPlayer->getName() << "'s turn" << endl;
			cout << "Bid or Pass" << endl;
			//cout << "Please note that you can't pass your turn if you're the first to bid on a power plant" << endl;
			cin >> BidOrPass;
			if (BidOrPass == "Pass" && currentPlayer == playerOrder[0])
				cout << "You cannot pass your turn since you're the first to bid on this power plant ";
			else if (BidOrPass == "Pass") {
				currentPlayer->Pass();
				playerOrder.erase(playerOrder.begin() + turn);

				//break;
			}
			else if (BidOrPass == "Bid" && initialbid) {
				cout << "Please pick the index of the powerplant you'd like to bid on, followed by your bid" << endl;
				//cout << "Please note that your bid must be at least the same value of the powerplant and higher than other bids" << endl;
				cin >> PPindex >> playerbid;
				//next line generates link ***********error cuz of getCard  to avoid player has manually put in at least card value
				//highestBid = ppmarket->GetvisiblePPlants().at(PPindex)->getCardValue(); // bid starts at PPcard value Value 

				if (playerbid >= highestBid) {
					if (currentPlayer->Auction(*ppmarket, PPindex, playerbid)) {
						//*highestbidder = *currentPlayer;
						highestbidder = currentPlayer;
						highestBid = playerbid;
						cout << "The highest bid is now " << highestBid << endl;
						initialbid = false;
					}
				}
				else
					cout << "Your bid is not high enough to purchase this powerplant" << endl;
			}
			else if (BidOrPass == "Bid") {
				cout << "Please enter by your bid" << endl;
				cin >> playerbid;
				if (playerbid > highestBid) {
					if (currentPlayer->Auction(*ppmarket, PPindex, playerbid)) {
						*highestbidder = *currentPlayer;
						highestBid = playerbid;
						cout << "The highest bid is now " << highestBid << endl;
					}
				}
				else
					cout << "Your bid is not high enough to purchase this powerplant" << endl;
			}
			//next turn
			turn = (turn + 1) % NumofPlayers;
			nextPlayerTurn = (nextPlayerTurn + 1) % playerOrder.size();
			}
	//}
		cout << "winner is " << highestbidder->getName() << endl;
		highestbidder->buyPowerPlant(*ppmarket, PPindex, playerbid);
		for (int i = 0; i < playerOrder.size(); ++i)
			if (playerOrder[i] == highestbidder)
				playerOrder.erase(playerOrder.begin() + i);

	}

	///printing the player possessions
	for (int i = 0; i < NumofPlayers; ++i)
		cout << *players.at(i) << "\n\n";
	for (vector<shared_ptr<Player>>::const_iterator i = players.begin(); i != players.end(); ++i) {
		cout << *i << "\n\n";
		//cout << *players.at(*i) << "\n\n";
	}

	// write info to file
	ofstream outfile("players.txt",ios_base::app);
	for (int i = 0; i < NumofPlayers; ++i) {
		if (outfile.is_open()) {
			outfile << *players.at(i);
			outfile << overviewCard;
			outfile.close();
		}
		else cout << "cannot open the file ";
	}
	
	system("pause");
	delete ppmarket;

	//delete PL;// replaced by shared pointers possible because for some reason this doesnt live out of scope
	return 0;
}


///// Used for determining the turn order **********error cuz of p1 and p2 ,doesnt have a class
//bool comparePlayerPriority(shared_ptr<Player> p1, shared_ptr<Player> p2) {
//
//	// Priority: 1 - Built Houses
//	if (p1->getBuiltHouses->size() > p2->getBuiltHouses.size())
//		return true;
//
//	if (p1->getBuiltHouses->size() < p2->getBuiltHouses.size())
//		return false;
//
//	// Priority: 2 - Highest power plant
//	if (p1->getHighestPowerPlant() > p2->getHighestPowerPlant())
//		return true;
//
//	return false;
//}
