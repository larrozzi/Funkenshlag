#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <random>
#include <time.h> 
#include <vector>
#include <map>
//#include <set>
#include "Player.h"
#include "SummaryCards.h"
#include "House.h"
//#include "PPmarket.h"
#include "PPMarketSingleton.h"

using namespace std;

class GameFunctions
{
private:

public:
	int NumofPlayers = 3;
	int turn = 0;
	int PPindex;
	int playerbid;
	bool initialbid;
	int highestBid;
	string BidOrPass;
	vector<shared_ptr<Player>> players;
	shared_ptr<Player> currentPlayer;
	shared_ptr<Player>highestbidder;
	vector<shared_ptr<Player>> InnerplayerOrder;
	vector<shared_ptr<Player>> OuterplayerOrder;

	PPMarketSingleton *PPmarketSingleton = PPmarketSingleton->GetInstance();

	GameFunctions();
	~GameFunctions();

	void setupDeckCards();
	void RandomplayerOrder(vector<shared_ptr<Player>> players);
	void AuctionTime();
	
};


