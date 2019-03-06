#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"

//using std::auto_ptr;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::vector;

Player::Player()
{
}

Player::Player(string name, int elektro, HouseColor color) : name{ name }, elektro{ elektro }, color{ color }{
}

Player ::~Player()
{
}

string Player::getName() const {
	return name;
}
void Player::setName( string name) {
	this->name = name;
}

int Player::getElektro() const {
	return elektro;
}
void Player::setElektro( int elektro) {
	this->elektro = elektro;
}

void Player::setColor( HouseColor color) {
	this->color = color;
}
HouseColor Player::getColor()const {
	return color;
}

vector<House>Player::grabhouses()
{
	for (int i=0; i < 22; i++) {
		houses.push_back(House(color));
	}
	return houses;
}

bool Player::buildinCity(string city) {
	mycities.push_back(city);
	return true;
	//if CityNode.getName() == city{
	//mycities.push_back("montreal");

	//return true;
	//}
	//else return false;
}
void  Player::printOwnedCities( ){
	for (vector<string>::const_iterator i = mycities.begin(); i != mycities.end(); ++i)
		cout << *i << ' ';
}

//bool Player::buildinCity(vector <CityNode>& city) {
//
//	mycities.push_back(CityNode("montreal",false, vector<string>& e, vector<int>& c));
//	return true;
//
//}


// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const Player& player)
{
	string separator = "---------------------------------------------------------------------------------\n";
	outs << separator << player.name + " has the following items: \n"
		<< player.elektro << " Elektros \n"
		<< player.houses.size() << " " << player.color << " colored Houses\n";
		// << player.printOwnedCities();
	return outs;
}


