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
//#include "PPmarket.h"
#include "PPMarketSingleton.h"


using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::vector;
using std::ifstream;
using std::shared_ptr;
using std::vector;
 
// constructors
Player::Player(){
}

Player::Player(string name, int elektro, HouseColor color) : name{ name }, elektro{ elektro }, color{ color }{
	coalCapacity = 0;
	oilCapacity = 0;
	garbageCapacity = 0;
	uraniumCapacity = 0;
	coalHeld = 0;
	oilHeld = 0;
	garbageHeld = 0;
	uraniumHeld = 0;
}

// destructor
Player ::~Player(){}

// setters
void Player::setName(string name) {this->name = name;}
void Player::setElektro(int elektro) {this->elektro = elektro;}
void Player::setColor(HouseColor color) {this->color = color;}

// getters
string Player::getName() const {return name;}
int Player::getElektro() const {return elektro;}
HouseColor Player::getColor()const {return color;}
vector <string> Player::getBuiltHouses()const { return mycities; }
vector<House>Player::getOwnedHouses()
{
    return ownedHouses;
}
int Player::getCoalCapacity() const { return coalCapacity; }
int Player::getOilCapacity() const { return oilCapacity; }
int Player::getGarbageCapacity() const { return garbageCapacity; }
int Player::getUraniumCapacity() const { return uraniumCapacity; }
int Player::getCoalHeld() const { return coalHeld; }
int Player::getOilHeld() const { return oilHeld; }
int Player::getGarbageHeld() const { return garbageHeld; }
int Player::getUraniumHeld() const { return uraniumHeld; }

// method to create the grab 22 houses from board
vector<House>Player::grabhouses(){
    for (int i=0; i < 22; ++i) {
        houses.push_back(House(color));
    }
    return houses;
}

// method to buy house
bool Player::buyHouse(shared_ptr<House> house)
{
    int housePrice = house->getPrice();
    
    // if cannot add house, city full
    //if (!house->getCity()->addHouse(house.get()))
        //return false;
    
    elektro -= housePrice;  // pay
    houses.push_back(*house); // save house to houses vector 
    return true;
}

//method to read cities from map file
void Player::readFile(){
    string firstword;
    string line;
    ifstream file;
    file.open("map.txt");

    if (file.is_open()) {
        while (getline(file, line))
        {
        firstword = line.substr(0, line.find('|'));
        mapcities.push_back(firstword);
        }
    }
    else cout << "cannot open the file ";
}

// method to build a house in a city
bool Player::buildinCity(string city) {
    bool matchedCity = false;
    for (vector<string>::const_iterator i = mapcities.begin(); i != mapcities.end(); ++i)
        if (*i == city) {
            matchedCity = true;
            mycities.push_back(city);
            return true;
        }
        else
        {
             matchedCity = false;
        }
        if (matchedCity==false)
        cout << city << " doesn't exist in the map" << endl;
    return true;
}

// method to print owned cities
void  Player::printOwnedCities( ){
    for (vector<string>::const_iterator i = mycities.begin(); i != mycities.end(); ++i)
        cout << *i << ' ';
}

bool Player::buyPowerPlant(PPMarketSingleton& ppMarketSingleton, int position, int price) {
    if (position <= 3 &&  elektro >= price) {
		if (myPowerPlants.size() < 3) {
			setElektro(getElektro() - price);
			OwnPowerPlant(ppMarketSingleton.getPlant(position));
			ppMarketSingleton.RemovePlant(position);
			ppMarketSingleton.DrawPlant();
			return true;
		}
    }
    return false;
}

void Player::buyResource(Type type, ResourceMarket* market) {
	int price = 0;
	int amount = 0;
	int resourceInMarket = 0;
	switch (type) {
	case COAL:
		resourceInMarket = market->getNumOfCoal();
		if (resourceInMarket == 0) {
			cout << "The market does not have any of that resource." << endl;
			break;
		}
		cout << "How much coal would you like to buy?: ";
		cin >> amount;
		
		while (resourceInMarket < amount) {
			cout << "The market does not have that much coal." << endl;
			cout << "How much coal would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
		}
		if (amount == -1) {
			break;
		}

		//Checks if the player has enough room to store the resourses they want to buy
		while(coalCapacity - coalHeld < amount) {
			cout << name << " does not have enough room." << endl;
			cout << "How much coal would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
		}
		if (amount == -1) {
			break;
		}

		//Determines the price of buying the asked number of resources
		price = market->determinePriceOfPurchase(amount, COAL);

		//Checks if the player has enough elektro
		while(elektro < price) {
			cout << name << " does not have enough elektro!" << std::endl;
			cout << "How much coal would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
			price = market->determinePriceOfPurchase(amount, COAL);
		}
		if (amount == -1) {
			break;
		}

		market->bought(type, amount);
		elektro -= price;
		coalHeld += amount;
		break;
	case OIL:
		resourceInMarket = market->getNumOfOil();
		if (resourceInMarket == 0) {
			cout << "The market does not have any of that resource." << endl;
			break;
		}
		cout << "How much oil would you like to buy?: ";
		cin >> amount;

		while (resourceInMarket < amount) {
			cout << "The market does not have that much oil." << endl;
			cout << "How much oil would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
		}
		if (amount == -1) {
			break;
		}

		//Checks if the player has enough room to store the resourses they want to buy
		while (oilCapacity - oilHeld < amount) {
			cout << name << " does not have enough room." << endl;
			cout << "How much oil would you like to buy?: ";
			cin >> amount;
		}
		//Determines the price of buying the asked number of resources
		price = market->determinePriceOfPurchase(amount, OIL);

		//Checks if the player has enough elektro
		while (elektro < price) {
			cout << name << " does not have enough elektro!" << std::endl;
			cout << "How much oil would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
			price = market->determinePriceOfPurchase(amount,OIL);
		}
		if (amount == -1) {
			break;
		}
		market->bought(type, amount);
		elektro -= price;
		oilHeld += amount;
		break;
	case GARBAGE:
		resourceInMarket = market->getNumOfGarbage();
		if (resourceInMarket == 0) {
			cout << "The market does not have any of that resource." << endl;
			break;
		}
		cout << "How much garbage would you like to buy?: ";
		cin >> amount;

		while (resourceInMarket < amount) {
			cout << "The market does not have that much garbage." << endl;
			cout << "How much garbage would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
		}
		if (amount == -1) {
			break;
		}
		//Checks if the player has enough room to store the resourses they want to buy
		while (garbageCapacity - garbageHeld < amount) {
			cout << name << " does not have enough room." << endl;
			cout << "How much garbage would you like to buy?: ";
			cin >> amount;
		}
		//Determines the price of buying the asked number of resources
		price = market->determinePriceOfPurchase(amount, GARBAGE);

		//Checks if the player has enough elektro
		while (elektro < price) {
			cout << name << " does not have enough elektro!" << std::endl;
			cout << "How much garbage would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
			price = market->determinePriceOfPurchase(amount, GARBAGE);
		}
		if (amount == -1) {
			break;
		}

		market->bought(type, amount);
		elektro -= price;
		garbageHeld += amount;
		break;
	case URANIUM:
		resourceInMarket = market->getNumOfUranium();
		if (resourceInMarket == 0) {
			cout << "The market does not have any of that resource." << endl;
			break;
		}
		cout << "How much uranium would you like to buy?: ";
		cin >> amount;

		while (resourceInMarket < amount) {
			cout << "The market does not have that much uranium." << endl;
			cout << "How much uranium would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
		}
		if (amount == -1) {
			break;
		}
		//Checks if the player has enough room to store the resourses they want to buy
		while (uraniumCapacity - uraniumHeld < amount) {
			cout << name << " does not have enough room." << endl;
			cout << "How much uranium would you like to buy?: ";
			cin >> amount;
		}
		//Determines the price of buying the asked number of resources
		price = market->determinePriceOfPurchase(amount, URANIUM);

		//Checks if the player has enough elektro
		while (elektro < price) {
			cout << name << " does not have enough elektro!" << std::endl;
			cout << "How much uranium would you like to buy?(Enter -1 to quit): ";
			cin >> amount;
			if (amount == -1) {
				break;
			}
			price = market->determinePriceOfPurchase(amount, URANIUM);
		}
		if (amount == -1) {
			break;
		}
		market->bought(type, amount);
		elektro -= price;
		uraniumHeld += amount;
		break;
	default:
		break;
	}
	cin.ignore();
}

 bool Player::OwnPowerPlant(shared_ptr<PowerPlantCards> powerplant) {
     if (myPowerPlants.size() == 3) return false;
	 switch (powerplant->getResourceType()) {
	 case COAL:
		 coalCapacity += powerplant->getCapacity();
		 break;
	 case OIL:
		 oilCapacity += powerplant->getCapacity();
		 break;
	 case GARBAGE:
		 garbageCapacity += powerplant->getCapacity();
		 break;
	 case URANIUM:
		 uraniumCapacity += powerplant->getCapacity();
		 break;
	 }
     myPowerPlants.push_back(powerplant);
     return true;
 }

 //check rule 
 bool Player::Pass() {
    cout << getName() << " passed their turn, and will no longer be able to purchase this powerplant." << endl;
     return true;
 }

 bool Player::Auction(const PPMarketSingleton& ppMarketSingleton, int position, int mybid) {
     if (position <= 3 && elektro >= mybid  ) {

         return true;
         // other players will see highest bid and try to outbid it
     }
     else cout << "You don't have enough elekro." << endl;
     return false;  //might need a way to let player go again
 }

 //void Player::ReplacePowerPlant(<shared_ptr<PowerPlant>> newplant, int toReplace) {
 //}

int Player::getHighestPowerPlant() {
    int max = 0;
    for (std::shared_ptr<PowerPlantCards> highestplant : myPowerPlants) {
        if (highestplant->getCardValue() > max)
            max = highestplant->getCardValue();
    }
    return max;
}

bool Player::HasElektro(int elektro)
{
    return this->elektro >= elektro;
}



 //// assignment operator
 // const Player& Player::operator = (const Player &player) {
    // elektro = player.elektro;
    // return *this;
 //}

// overloading == operator
//bool Player::operator==(const Player& p) const
//{
//    return (this->name == p.name &&
//            this->elektro == p.elektro &&
//            this->houses == p.houses &&
//            this->mycities == p.mycities &&
//            this->mapcities == p.mapcities &&
//            this->myPowerPlants == p.myPowerPlants &&
//            this->color == p.color &&
//            this->mybid == p.mybid);
//}

// overloading output stream operator with cities
std::ostream& operator<<(std::ostream& outs, const Player& player){
    string separator = "\n\n=========================================================================================\n\n";
	outs << separator << player.name + " has the following items: \n"
		<< "\t" << player.elektro << " Elektros \n"
		<< "\t" << player.houses.size() << " " << player.color << " colored Houses.\n"
		<< "\t" << "Coal: " << player.coalHeld << std::endl
		<< "\t" << "Oil: " << player.oilHeld << std::endl
		<< "\t" << "Garbage: " << player.garbageHeld << std::endl
		<< "\t" << "Uranium: " << player.uraniumHeld << std::endl
        << "He owns the following power plants: ";

        for (vector<shared_ptr<PowerPlantCards>>::const_iterator p = player.myPowerPlants.begin(); p != player.myPowerPlants.end(); ++p)
            outs << **p << ' ';
            outs << endl; 
            outs << "And owns the following cities: ";
        string cities;
        for (vector<string>::const_iterator c = player.mycities.begin(); c != player.mycities.end(); ++c)
            outs << *c << ' ';
            outs << endl;
    return outs;
}

/** Strategy Design Pattern for PlayerBehaviour **/

// Plugs in a specific Behaviour to be used
Player::Player(PlayerBehaviour* iniBehaviour) {
    playB = iniBehaviour;
}

Player::Player(PlayerBehaviour* iniBehaviour, string name, int elektro, HouseColor color) : playB(iniBehaviour), name(name), elektro(elektro), color(color)
{
       coalCapacity = 0;
       oilCapacity = 0;
       garbageCapacity = 0;
       uraniumCapacity = 0;
       coalHeld = 0;
       oilHeld = 0;
       garbageHeld = 0;
       uraniumHeld = 0;
}

void Player::setPlayerBehaviour(PlayerBehaviour* newBehaviour) {
    playB = newBehaviour;
}

// This method executes a different depending on what behaviour was * inserted
string Player::executePlayerBehaviour() {
   return playB->executeBehaviour();
}

string Player::executeAuction(bool& Initialbid, int& currentbid) {
	return playB->executeAuction(Initialbid, currentbid);
}

 string Player::executeAuction(bool& Initialbid, int& currentbid, int PPindex) {
	return playB->executeAuction(Initialbid, currentbid, PPindex);
}

