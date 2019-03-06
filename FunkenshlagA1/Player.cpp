//  COMP345A1
//
//  Created by Yassine Laaroussi 2019-02-08.
//  Updated 2019-03-05
//

#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::vector;

// constructors
Player::Player()
{
}

Player::Player(string name, int elektro, HouseColor color) : name{ name }, elektro{ elektro }, color{ color }{
}

// destructor
Player ::~Player()
{
}

// setters
void Player::setName(string name) {
	this->name = name;
}
void Player::setElektro(int elektro) {
	this->elektro = elektro;
}
void Player::setColor(HouseColor color) {
	this->color = color;
}

// getters
string Player::getName() const {
	return name;
}
int Player::getElektro() const {
	return elektro;
}
HouseColor Player::getColor()const {
	return color;
}

// method to create the grab 22 houses from board
vector<House>Player::grabhouses()
{
	for (int i=0; i < 22; i++) {
		houses.push_back(House(color));
	}
	return houses;
}

// method to build own a city
bool Player::buildinCity(string city) {
	mycities.push_back(city);
	return true;
}
// method to print owned cities
void  Player::printOwnedCities( ){
	for (vector<string>::const_iterator i = mycities.begin(); i != mycities.end(); ++i)
		cout << *i << ' ';
}

//// overloading output stream operator without city
//std::ostream& operator<<(std::ostream& outs, const Player& player)
//{
//	string separator = "---------------------------------------------------------------------------------\n";
//	outs << separator << player.name + " has the following items: \n"
//		<< player.elektro << " Elektros \n"
//		<< player.houses.size() << " " << player.color << " colored Houses\n";
//		// << player.printOwnedCities();
//	return outs;
//}


// overloading output stream operator with cities
std::ostream& operator<<(std::ostream& outs, const Player& player)
{
	string separator = "---------------------------------------------------------------------------------\n";
	outs << separator << player.name + " has the following items: \n"
		<< "\t" << player.elektro << " Elektros \n"
		<< "\t" << player.houses.size() << " " << player.color << " colored Houses\n"
		<< "And owns the following cities: ";
	for (vector<string>::const_iterator i = player.mycities.begin(); i != player.mycities.end(); ++i)
		cout << *i << ' ';
	return outs;
}

