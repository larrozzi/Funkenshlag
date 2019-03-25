////////  COMP345A1
////////
////////  Created by Yassine Laaroussi 2019-02-08.
////////  Updated 2019-03-06
//
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <memory>
//#include <algorithm>
//#include "Player.h"
//#include "SummaryCards.h"
//#include "House.h"
//#include "PPmarket.h"
//
//
//using namespace std;
//using std::cout;
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
//    int fullturn;
//    int phase = 1;
//
//    vector<shared_ptr<Player>> players;
//    shared_ptr<Player> currentPlayer;
//    vector<shared_ptr<Player>> playerOrder;
//
//    cout << "Hello and Welcome to Powergrid\n\n";
//    cout<< "Enter the Number of Players\n\n";
//    cin >> NumofPlayers;
//     
//            ///configuring the players one by one
//    for (int i = 0; i < NumofPlayers; i++) {
//            ///creating a Player
//        cout << "Please enter your name  \n"<<++i;
//        cin >> name;
//        cout << "Now please pick a HOUSE COLOR among the following: RED, BLUE, GREEN, YELLOW, BLACK, PINK.\n";
//        cin >> color;
//        clr = convert(color);
//
//            ///initializing a Player
//    //    Player* PL = new Player(name, 50, clr);
//    //    players.push_back(PL);
//        players.push_back(std::make_shared<Player>(name, 50, clr));
//            /// taking 22 house items
//        //PL->grabhouses();
//        players.at(i)->grabhouses();
//
//            /// taking an overview card
//        for (int i = 0; i < NumofPlayers; i++) {
//            overviewCard = SummaryCards(*players.at(i));
//            cout << overviewCard;
//        }
//
//        /*     Owning a city 
//        cout << "Please enter the city you'd like to build a house in \n";
//        cin >> cityName;
//        PL->readFile();
//        PL->buildinCity(cityName);*/
//    }
//
//        ///Auction time
//    Player highestbidder;
//
//    vector<PowerPlantCards> Pplants = PowerPlantCards::createPowerPlantCards();  // holds the created PowerPlantCards
//
//    PPmarket *ppmarket = new PPmarket(); //creating a PP market to show the visible first 8 plants to players
//    vector<shared_ptr<PowerPlantCards>> PPlantsSptr; //the market PPlants in this vector need to point to the plants created    
//    
//    vector<shared_ptr<PowerPlantCards> > PPlantsSptr;
//    for ( int i=0; i<=46; i++)
//    PPlantsSptr.push_back(std::make_shared<PowerPlantCards>(Pplants.at(i)));
//
//    //shared_ptr<PowerPlantCards> sharedptr(new PowerPlantCards); //same as next two lines ?
//    /*PowerPlantCards* pp = new PowerPlantCards;  each pp inside the Pplants
//    std::vector<std::shared_ptr<PowerPlantCards>> PPlantsSptr;
//    PPlantsSptr.emplace_back(pp);
//    */
//
//    //fill a vector of pointers to the powerplants created already
//    ppmarket->SetMPlants(PPlantsSptr);
//
//    //make the market ready for auction, filling the visibleplants vector
//    ppmarket->Setup();
//
//    // printing the PPmarket
//    ppmarket->printPPmarket();
//
//        /// random order before first Auction
//    for (auto player : players)
//        playerOrder.push_back(player);
//    random_shuffle(playerOrder.begin(), playerOrder.end());
//
//    // Set current player
//    currentPlayer = playerOrder[0];
//
//    //after player order 
//    currentPlayer->Auction(*ppmarket, 0, 5);
//
//    //highestbidder = currentPlayer;
//
//    ///printing the player possessions
//    for (int i = 0; i < NumofPlayers; i++)
//        cout << *players.at(i) << "\n\n";
//    for (vector<shared_ptr<Player>>::const_iterator i = players.begin(); i != players.end(); ++i) {
//        cout << *i << "\n\n";
//        //cout << *players.at(*i) << "\n\n";
//    }
//
//    // write info to file
//    ofstream outfile("players.txt",ios_base::app);
//    for (int i = 0; i < NumofPlayers; i++) {
//        if (outfile.is_open()) {
//            outfile << *players.at(i);
//            outfile << overviewCard;
//            outfile.close();
//        }
//        else cout << "cannot open the file ";
//    }
//    
//    system("pause");
//    delete ppmarket;
//
//    //delete PL;// replaced by shared pointers possible because for some reason this doesnt live out of scope
//    return 0;
//}
