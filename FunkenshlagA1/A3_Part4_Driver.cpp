//////  COMP345A1
////////
////////  Created by Yassine Laaroussi 2019-03-27.
////////  Updated 2019-03-06
//
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <memory>
//#include <algorithm>
//#include <random>
//#include <time.h> 
//#include <vector>
//#include <map>
//#include <set>
//#include "Player.h"
//#include "SummaryCards.h"
//#include "House.h"
////#include "PPmarket.h"
//#include "PPMarketSingleton.h"
//
//using namespace std;
//
//
//static HouseColor convert(const std::string& clr)
//{
//    if (clr == "NO_COLOR")        return NO_COLOR;
//    else if (clr == "RED")        return RED;
//    else if (clr == "BLUE")        return BLUE;
//    else if (clr == "GREEN")    return GREEN;
//    else if (clr == "YELLOW")    return YELLOW;
//    else if (clr == "BLACK")    return BLACK;
//    else if (clr == "PINK")        return PINK;
//    else return NO_COLOR;
//}
//
//int main()
//{
//    string name;
//    string color;
//    HouseColor clr;
//    string cityName;
//    SummaryCards overviewCard;
//    int NumofPlayers;
//
//    int turn = 0;
//    int PPindex;
//    int playerbid;
//    bool initialbid;
//    int highestBid;
//    bool alreadyPickedClr = false;
//    string BidOrPass;
//    vector<shared_ptr<Player>> players;
//    shared_ptr<Player> currentPlayer;
//    shared_ptr<Player>highestbidder;
//    vector<shared_ptr<Player>> InnerplayerOrder;
//    vector<shared_ptr<Player>> OuterplayerOrder;
//
//
//    cout << "Hello and Welcome to Powergrid\n\n";
//    cout << "Enter the Number of Players\n" << "> ";
//    cin >> NumofPlayers;
//
//    while (NumofPlayers < 2 || NumofPlayers > 6) {
//        cout << "Number of players should be between 2 and 6." << endl;
//        cout << "Enter the Number of Players\n" << "> ";
//        cin >> NumofPlayers;
//    }
//
//            ///configuring the players one by one
//    for (int i = 0; i < NumofPlayers; ++i) {
//            ///creating a Player
//        cout << "" << endl;
//        cout << "Please enter your name  \n";
//        cout << "> ";
//        cin >> name;
//        cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
//        cout << "> ";
//        cin >> color;
//        clr = convert(color);
//
//        for (int i = 0; i < players.size(); i++) {
//            if (players.at(i)->getColor() == clr) {
//                alreadyPickedClr = true;
//            }
//        }
//        while ((color != "RED" && color != "BLUE" && color != "GREEN" && color != "YELLOW" && color != "BLACK" && color != "PINK")|| alreadyPickedClr) {
//            cout << "Please pick a valid color (either you entered an invalid color or the color was already picked by another player)." << endl;
//            cout << "Please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
//            cout << "> ";
//            cin >> color;
//            clr = convert(color);
//            for (int i = 0; i < players.size(); i++) {
//                if (players.at(i)->getColor() == clr) {
//                    alreadyPickedClr = true;
//                }
//                else
//                    alreadyPickedClr = false;
//            }
//        }
//
//            ///initializing a Player
//        players.push_back(std::make_shared<Player>(name, 50, clr));
//            /// taking 22 house items
//        players.at(i)->grabhouses();
//            /// taking an overview card
//        cout << overviewCard;
//
//    }
//
//        ///Auction time
//    vector<PowerPlantCards> Pplants = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
//
//    //replaced with a singleton
//    //PPmarket *ppmarket = new PPmarket(); //creating a PP market that will show the visible first 8 plants to players
//    
//    PPMarketSingleton *PPmarketSingleton = PPmarketSingleton->GetInstance();
//    cout << PPmarketSingleton << endl;
//
//    vector<shared_ptr<PowerPlantCards>> PPlantsSptr; //the market PPlants in this vector need to point to the plants created
//
//    Pplants.size();
//
//    for ( int i=0; i<42; ++i)
//    PPlantsSptr.push_back(std::make_shared<PowerPlantCards>(Pplants[i])); //the powerplant market is now linked to the created pplants
//
//    //fill a vector of pointers to the powerplants created already
//    PPmarketSingleton->SetMPlants(PPlantsSptr);
//
//    //make the market ready for auction, filling the visibleplants vector
//    PPmarketSingleton->Setup();
//
//    // printing the PPmarket
//    cout << "" << endl;
//    PPmarketSingleton->printPPmarket();  // test needed
//
//    cout << "Phase I" << endl;
//    cout << "Random Player order on first Auction as follows:" << endl;
//
//
//        /// random Player Order before first Auction
//    vector<int> rvec(NumofPlayers);
//    for (int i = 0; i < NumofPlayers; ++i)
//        rvec[i] = i;
//    auto rng = std::default_random_engine{};
//    shuffle(begin(rvec), end(rvec), rng);
//    for (int i = 0; i < NumofPlayers; ++i) {
//        InnerplayerOrder.push_back(players[rvec[i]]);
//        OuterplayerOrder.push_back(players[rvec[i]]);
//        cout << InnerplayerOrder[i]->getName() << ' ';
//    }
//
//    cout << "" << endl;
//    cout << "----------------------------------------------------------------------------" << endl;
//    cout << "" << endl;
//    cout << "Phase II" << endl;
//    cout << "Let the Auctions begin" << endl;
//    cout << "" << endl;
//
//    //  loop for auctions
//    while (OuterplayerOrder.size()>1){ //  rounds necessary for each player to win a powerplant
//        initialbid = true;
//        int turnNextPlayer = turn + 1;
//
//        //next line generates link ***********error cuz of getCard  to avoid player has manually put in at least card value
//
//        highestBid = PPmarketSingleton->GetvisiblePPlants().at(0)->getCardValue(); // bid starts at PPcard value Value
//
//        InnerplayerOrder = OuterplayerOrder;
//        cout << "----------------------------------------------------------------------------" << endl;
//        cout << "New round of auction." << endl;
//
//        while (InnerplayerOrder.size()>1) { // number of turns to purchase one pp, end loop after only one player is remaining
//            // Set current player by order
//                currentPlayer = InnerplayerOrder[turn]; //player order inside a round
//                cout << InnerplayerOrder.size()<< " players are still in this round of auction."<<endl;
//
//                //current player auction
//            cout << currentPlayer->getName() << "'s turn, Elekro: " << currentPlayer->getElektro()<< endl;
//            cout << "BID or PASS" << endl;
//            cout << "> ";
//            cin >> BidOrPass;
//            if (BidOrPass == "PASS" && initialbid) {
//                cout << "You cannot pass your turn since you're the first to bid on this power plant." << endl;
//                cout << "Please try again" << endl;
//                turn--;
//                turnNextPlayer--;
//            }
//            else if (BidOrPass == "PASS") {
//                currentPlayer->Pass();
//                InnerplayerOrder.erase(InnerplayerOrder.begin() + turn);
//                turn--;
//                turnNextPlayer--;
//            }
//            else if (BidOrPass == "BID" && initialbid) {
//                cout << "Please pick the index of the powerplant you'd like to bid on, followed by your bid." << endl;
//                cout << "> ";
//                cin >> PPindex >> playerbid;
//
//                if (playerbid >= highestBid) {
//                    if (currentPlayer->Auction(*PPmarketSingleton, PPindex, playerbid)) {
//                        highestbidder = currentPlayer;
//                        highestBid = playerbid;
//                        cout << "The initial bid is " << highestBid << endl;
//                        initialbid = false;
//                    }
//                }
//                else {
//                    cout << "Your bid is not high enough to purchase this powerplant." << endl;
//                    cout << "Please try again" << endl;
//                    turn--;
//                    turnNextPlayer--;
//                }
//            }
//            else if (BidOrPass == "BID") {
//                cout << "Please enter your bid" << endl;
//                cout << "> ";
//                cin >> playerbid;
//                if (playerbid > highestBid) {
//                    if (currentPlayer->Auction(*PPmarketSingleton, PPindex, playerbid)) {
//                        highestbidder = currentPlayer;
//                        highestBid = playerbid;
//                        cout << "The highest bid is now " << highestBid << endl;
//                    }
//                }
//                else{
//                    cout << "Your bid is not high enough to purchase this powerplant." << endl;
//                    cout << "Please try again" << endl;
//                    turn--;
//                    turnNextPlayer--;
//                    }
//            }
//            //next turn
//            turn = (turn + 1) % InnerplayerOrder.size();
//            turnNextPlayer = (turnNextPlayer + 1) % InnerplayerOrder.size();
//            cout << "" << endl;
//            }
//     //}
//        cout << "The winner of this auction round is: " << highestbidder->getName() << endl;
//        highestbidder->buyPowerPlant(*PPmarketSingleton, PPindex, playerbid);
//            // printing the PPmarket
//            cout << "" << endl;
//            cout << "the new Power plant market is now: " << endl;
//            cout << "" << endl;
//            PPmarketSingleton->printPPmarket();
//
//            //remove winner from player order
//        for (int i = 0; i < OuterplayerOrder.size(); ++i)
//            if (OuterplayerOrder[i] == highestbidder)
//                OuterplayerOrder.erase(OuterplayerOrder.begin() + i);
//    }
//
//    ///printing the player possessions
//    for (int i = 0; i < NumofPlayers; ++i)
//        cout << *players.at(i) << "\n";
//
//    system("pause");
//
//   // delete ppmarket;
//    PPMarketSingleton::ResetInstance();
//    return 0;
//}
//
