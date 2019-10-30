 
#include "GameFunctions.h"

GameFunctions::GameFunctions()
{

}

GameFunctions::~GameFunctions()
{
}


 void GameFunctions::setupDeckCards() {
         vector<PowerPlantCards> Pplants = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
//
    //replaced with a singleton
    //PPmarket *ppmarket = new PPmarket(); //creating a PP market that will show the visible first 8 plants to players

    //     PPMarketSingleton *PPmarketSingleton = PPmarketSingleton->GetInstance();
    //     cout << PPmarketSingleton << endl;

         vector<shared_ptr<PowerPlantCards>> PPlantsSptr; //the market PPlants in this vector need to point to the plants created

         Pplants.size();

         for (int i = 0; i < 42; ++i)
             PPlantsSptr.push_back(std::make_shared<PowerPlantCards>(Pplants[i])); //the powerplant market is now linked to the created pplants

             //fill a vector of pointers to the powerplants created already
         PPmarketSingleton->SetMPlants(PPlantsSptr);

         //make the market ready for auction, filling the visibleplants vector
         PPmarketSingleton->Setup();

         // printing the PPmarket
         cout << "" << endl;
         PPmarketSingleton->printPPmarket();  
     }

 void GameFunctions::RandomplayerOrder(vector<shared_ptr<Player>> players) {
     /// random Player Order before first Auction
     vector<int> rvec(3);
     //vector<int> rvec(NumofPlayers);
     for (int i = 0; i < 3; ++i)
         rvec[i] = i;
     auto rng = std::default_random_engine{};
     shuffle(begin(rvec), end(rvec), rng);
     for (int i = 0; i < NumofPlayers; ++i) {
         InnerplayerOrder.push_back(players[rvec[i]]);
         OuterplayerOrder.push_back(players[rvec[i]]);
         cout << InnerplayerOrder[i]->getName() << ' ';
     }     
 }

 void GameFunctions::AuctionTime() {

   /* cout << "Phase I" << endl;
    cout << "Random Player order on first Auction as follows:" << endl;

    RandomplayerOrder();

    cout << "" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Phase II" << endl;*/

    cout << "Let the Auctions begin" << endl;
    cout << "" << endl;

    //  loop for auctions
    while (OuterplayerOrder.size()>1){ //  rounds necessary for each player to win a powerplant
        initialbid = true;
        int turnNextPlayer = turn + 1;

        //next line generates link ***********error cuz of getCard  to avoid player has manually put in at least card value

        highestBid = PPmarketSingleton->GetvisiblePPlants().at(0)->getCardValue(); // bid starts at PPcard value Value

        InnerplayerOrder = OuterplayerOrder;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "New round of auction." << endl;

        while (InnerplayerOrder.size()>1) { // number of turns to purchase one pp, end loop after only one player is remaining
            // Set current player by order
                currentPlayer = InnerplayerOrder[turn]; //player order inside a round
                cout << InnerplayerOrder.size()<< " players are still in this round of auction."<<endl;

                //current player auction
            cout << currentPlayer->getName() << "'s turn, Elekro: " << currentPlayer->getElektro() << " " << currentPlayer->executePlayerBehaviour() << endl;
            cout << "BID or PASS" << endl;
            cout << "> ";
           // cin >> BidOrPass;
            BidOrPass= currentPlayer->executeAuction(initialbid, highestBid);
            cout << BidOrPass << endl;

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
               // cin >> PPindex >> playerbid;
				PPindex = currentPlayer->executeAuction(playerbid,3,true);
				cout << PPindex << endl;
				cout << "> ";
				playerbid= currentPlayer->executeAuction(playerbid,3,false);
				cout << playerbid << endl;
				
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
                //cin >> playerbid;
                playerbid=currentPlayer->executeAuction(playerbid);
                cout << playerbid << endl;

                if (playerbid > highestBid) {
                    if (currentPlayer->Auction(*PPmarketSingleton, PPindex, playerbid)) {
                        highestbidder = currentPlayer;
                        highestBid = playerbid;
                        cout << "The highest bid is now " << highestBid << endl;
                    }
                }
                else{
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
     //}
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
            //gameTurn->setPlayersTurn(currentPlayer);
            cout << "BID or PASS" << endl;
            cout << "> ";
            //cin >> BidOrPass;
            BidOrPass = "BID";
            cout << BidOrPass << endl;
            
            if (BidOrPass == "BID") {
                cout << "Please pick the index of the powerplant you'd like to bid on, followed by your bid." << endl;
                cout << "> ";
                //cin >> PPindex >> playerbid;
                PPindex = currentPlayer->executeAuction(playerbid,3,true);
                cout << PPindex << endl;
                cout << "> ";
                playerbid= currentPlayer->executeAuction(playerbid,3,false);
                cout << playerbid << endl;
                currentPlayer->buyPowerPlant(*PPmarketSingleton, PPindex, playerbid);
                cout << "The winner of this auction round is: " << currentPlayer->getName() << endl;
            }
        }
    }
}

