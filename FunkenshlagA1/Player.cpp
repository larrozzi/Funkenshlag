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
#include "PPmarket.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::vector;
using std::ifstream;
using std::shared_ptr;
 
// constructors
Player::Player(){
}

Player::Player(string name, int elektro, HouseColor color) : name{ name }, elektro{ elektro }, color{ color }{
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

// method to create the grab 22 houses from board
vector<House>Player::grabhouses(){
	for (int i=0; i < 22; ++i) {
		houses.push_back(House(color));
	}
	return houses;
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

bool Player::buyPowerPlant(PPmarket& ppMarket, int position, int price) {
	if (position <= 3 &&  elektro >= price) {
		setElektro(getElektro() - price);

		if (myPowerPlants.size() <= 3)
		AddPowerPlant(ppMarket.getPlant(position));
		ppMarket.RemovePlant(position);
		ppMarket.DrawPlant();
		return true;
	}
	return false;
}

 bool Player::AddPowerPlant(shared_ptr<PowerPlantCards> powerplant) {
	 if (myPowerPlants.size() == 3) return false;
	 myPowerPlants.push_back(powerplant);
	 return true;
 }

 //check rule 
 bool Player::Pass() {
	 /*if (myPowerPlants.size() == 0) {
		 cout << "you can't pass your turn if you don't own any powerplants";
		 return false;
	 }
*/ 
	cout << "You passed your turn, you will no longer be able to purchase this powerplant" <<endl;
	cout << getName() << "passed his turn, and will no longer be able to purchase this powerplant " << endl;
	 return true;
 }

 bool Player::Auction(const PPmarket& ppMarket, int position, int mybid) {
	 if (position <= 3 && elektro >= mybid  ) {   

		 return true;
		 // other players will see highest bid and try to outbid it
	 }
	 else cout << "You don't have enough elekro" << endl;
	 return false;  //might need a way to let player go again
 }

 //void Player::ReplacePowerPlant(<shared_ptr<PowerPlant>> newplant, int toReplace) {
 //}

//int Player::getHighestPowerPlant() {
//	int max; //*********** error  not initialzed
//	for (std::shared_ptr<PowerPlantCards> highestplant : myPowerPlants) {
//		if (highestplant->getCardValue() > max)
//			max = highestplant->getCardValue();
//	}
//	return max;
//}


 //// assignment operator
 // Player& Player::operator = (const Player &player) {
	// elektro = player.elektro;
	// return *this;
 //}


// overloading output stream operator with cities
std::ostream& operator<<(std::ostream& outs, const Player& player){
	string separator = "\n\n=========================================================================================\n\n";
	outs << separator << player.name + " has the following items: \n"
		<< "\t" << player.elektro << " Elektros \n"
		<< "\t" << player.houses.size() << " " << player.color << " colored Houses\n"
		<< "he owns the following power plants: "

		<< "And owns the following cities: ";
	string cities;
	for (vector<string>::const_iterator i = player.mycities.begin(); i != player.mycities.end(); ++i)
		outs << *i << ' ';
		outs << endl;
	return outs;
}

