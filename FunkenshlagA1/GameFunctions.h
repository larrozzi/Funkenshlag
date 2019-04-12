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
#include "GameTurnSubject.h"
//#include "PPmarket.h"
#include "PPMarketSingleton.h"

using namespace std;

class GameFunctions
{
private:

public:
	int NumofPlayers;
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

	GameFunctions(int,vector<shared_ptr<Player>> players);
	~GameFunctions();

	void AuctionTime(GameTurnSubject*);
	void RandomPlayerOrder();
	void setupDeckCards();
};

bool playerPriority(shared_ptr<Player> p1, shared_ptr<Player> p2);
void updatePlayOrder(bool reverse, vector<shared_ptr<Player>> playerOrder);


