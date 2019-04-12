#include "GameFunctions.h"
#include "Player.h"
#include "GameTurnSubject.h"
#include <algorithm>
#include <memory>
#include "Building.h"

GameFunctions::GameFunctions(int numOfPlayers,vector<shared_ptr<Player>> players)
{
	this->NumofPlayers = numOfPlayers;
	this->players = players;
}

GameFunctions::~GameFunctions()
{
}


	static  HouseColor convert(const std::string& clr)
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


 void GameFunctions::setupDeckCards() {
		 vector<PowerPlantCards> Pplants = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
//
	//replaced with a singleton
	//PPmarket *ppmarket = new PPmarket(); //creating a PP market that will show the visible first 8 plants to players
		

		 vector<shared_ptr<PowerPlantCards>> PPlantsSptr; //the market PPlants in this vector need to point to the plants created

		 Pplants.size();

		 for (int i = 0; i < 42; ++i)
			 PPlantsSptr.push_back(std::make_shared<PowerPlantCards>(Pplants[i])); //the powerplant market is now linked to the created pplants

			 //fill a vector of pointers to the powerplants created already
		 PPmarketSingleton->SetMPlants(PPlantsSptr);

		 //make the market ready for auction, filling the visibleplants vector
		 PPmarketSingleton->Setup();

	 }

 void GameFunctions::RandomPlayerOrder() {
	 /// random Player Order before first Auction
	 vector<int> rvec(NumofPlayers);
	 for (int i = 0; i < NumofPlayers; ++i)
		 rvec[i] = i;
	 auto rng = std::default_random_engine{};
	 shuffle(begin(rvec), end(rvec), rng);
	 for (int i = 0; i < NumofPlayers; ++i) {
		 InnerplayerOrder.push_back(players[rvec[i]]);
		 OuterplayerOrder.push_back(players[rvec[i]]);
	 }
	 players.clear();
	 for (int i = 0; i < NumofPlayers; ++i) {
		 players.push_back(InnerplayerOrder[i]);
	 }
	 currentPlayer = players[0];
 }

// used to determine the player turn order
bool playerPriority(shared_ptr<Player> p1, shared_ptr<Player> p2) {

	// priority1 - based on number of Houses owned
	if (p1->getOwnedHouses().size() > p2->getOwnedHouses().size())
		return true;

	if (p1->getOwnedHouses().size() < p2->getOwnedHouses().size())
		return false;

	// priority2 - based on Highest powerplant owned
	if (p1->getHighestPowerPlant() > p2->getHighestPowerPlant())
		return true;

	return false;
}

// updating player order
void updatePlayOrder(bool reverse, vector<shared_ptr<Player>> playerOrder,GameFunctions* game) {
	sort(playerOrder.begin(), playerOrder.end(), playerPriority);

	if (reverse) // if reverse is true= reverses the player order
		std::reverse(playerOrder.begin(), playerOrder.end());
	
	game->currentPlayer = playerOrder[0];
	
}
void updatePlayOrder(bool reverse, vector<shared_ptr<Player>> playerOrder) {
	sort(playerOrder.begin(), playerOrder.end(), playerPriority);

	if (reverse) // if reverse is true= reverses the player order
		std::reverse(playerOrder.begin(), playerOrder.end());

}

 void GameFunctions::AuctionTime(GameTurnSubject* gameTurn) {

    cout << "Let the Auctions begin" << endl;
    cout << "" << endl;

	// printing the PPmarket
	cout << "" << endl;
	PPmarketSingleton->printPPmarket();

    //  loop for auctions
	while (OuterplayerOrder.size() > 1) { //  rounds necessary for each player to win a powerplant
		initialbid = true;
		int turnNextPlayer = turn + 1;

		//next line generates link ***********error cuz of getCard  to avoid player has manually put in at least card value

		highestBid = PPmarketSingleton->GetvisiblePPlants().at(0)->getCardValue(); // bid starts at PPcard value Value

		InnerplayerOrder = OuterplayerOrder;
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "New round of auction." << endl;

		while (InnerplayerOrder.size() > 1) { // number of turns to purchase one pp, end loop after only one player is remaining
			// Set current player by order
			currentPlayer = InnerplayerOrder[turn]; //player order inside a round
			gameTurn->setPlayersTurn(currentPlayer);
			cout << InnerplayerOrder.size() << " players are still in this round of auction." << endl;

			//current player auction
			cout << "BID or PASS" << endl;
			cout << "> ";
			cin >> BidOrPass;
			//currentPlayer->executePlayerBehaviour();

			if (BidOrPass == "PASS" && initialbid) {
				cout << "You cannot pass your turn since you're the first to bid on this power plant." << endl;
				cout << "Please try again" << endl;
				turn--;
				turnNextPlayer--;
			}
			else if (BidOrPass == "PASS") {
				currentPlayer->Pass();
				InnerplayerOrder.erase(InnerplayerOrder.begin() + turn);
				turn--;
				turnNextPlayer--;
			}
			else if (BidOrPass == "BID" && initialbid) {
				cout << "Please pick the index of the powerplant you'd like to bid on, followed by your bid." << endl;
				cout << "> ";
				cin >> PPindex >> playerbid;
				//currentPlayer->executePlayerBehaviour();

				if (playerbid >= highestBid) {
					if (currentPlayer->Auction(*PPmarketSingleton, PPindex, playerbid)) {
						highestbidder = currentPlayer;
						highestBid = playerbid;
						cout << "The initial bid is " << highestBid << endl;
						initialbid = false;
					}
				}
				else {
					cout << "Your bid is not high enough to purchase this powerplant." << endl;
					cout << "Please try again" << endl;
					turn--;
					turnNextPlayer--;
				}
			}
			else if (BidOrPass == "BID") {
				cout << "Please enter your bid" << endl;
				cout << "> ";
				cin >> playerbid;
				//currentPlayer->executePlayerBehaviour();
				if (playerbid > highestBid) {
					if (currentPlayer->Auction(*PPmarketSingleton, PPindex, playerbid)) {
						highestbidder = currentPlayer;
						highestBid = playerbid;
						cout << "The highest bid is now " << highestBid << endl;
					}
				}
				else {
					cout << "Your bid is not high enough to purchase this powerplant." << endl;
					cout << "Please try again" << endl;
					turn--;
					turnNextPlayer--;
				}
			}
			//next turn
			turn = (turn + 1) % InnerplayerOrder.size();
			turnNextPlayer = (turnNextPlayer + 1) % InnerplayerOrder.size();
			cout << "" << endl;
		}
		cout << "The winner of this auction round is: " << highestbidder->getName() << endl;
		highestbidder->buyPowerPlant(*PPmarketSingleton, PPindex, playerbid);
		// printing the PPmarket
		cout << "" << endl;
		cout << "the new Power plant market is now: " << endl;
		cout << "" << endl;
		PPmarketSingleton->printPPmarket();

		//remove winner from player order
		for (int i = 0; i < OuterplayerOrder.size(); ++i)
			if (OuterplayerOrder[i] == highestbidder)
				OuterplayerOrder.erase(OuterplayerOrder.begin() + i);

		if (OuterplayerOrder.size() == 1) {
			currentPlayer = OuterplayerOrder.at(0);
			gameTurn->setPlayersTurn(currentPlayer);
			cout << "BID or PASS" << endl;
			cout << "> ";
			cin >> BidOrPass;

			if (BidOrPass == "BID") {
				cout << "Please pick the index of the powerplant you'd like to bid on, followed by your bid." << endl;
				cout << "> ";
				cin >> PPindex >> playerbid;
				currentPlayer->buyPowerPlant(*PPmarketSingleton, PPindex, playerbid);
				cout << "The winner of this auction round is: " << currentPlayer->getName() << endl;
			}
		}
	}
	cin.ignore();
}