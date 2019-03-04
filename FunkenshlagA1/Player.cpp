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

Player::Player()
{
}

Player::Player(string name, int elektro, HouseColor color) : name{ name }, elektro{ elektro }, color{ color }{

	cout << "player created" << endl;
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

//
////************** build houses in cities if possible *****************
//bool Player::BuildHouse(CityNode& city, House& house) {
//	int houseCost = city.getPrice();
//	if (!city.unUse() ) //err :this should return bool
//		return false;
//	else {
//		//elektro -= houseCost;
//		setElektro(getElektro() - houseCost);
//		houses.push_back(house); // add house on vector houses
//		return true;
//	}

// overloading output operator for the enum HouseColor
std::ostream& operator<<(std::ostream& outs, const HouseColor& color)
{
	const char* c = 0;
#define PROCESS_VAL(p) case(p): c = #p; break;
	switch (color) {
		PROCESS_VAL(NO_COLOR);
		PROCESS_VAL(RED);
		PROCESS_VAL(BLUE);
		PROCESS_VAL(GREEN);
		PROCESS_VAL(YELLOW);
		PROCESS_VAL(BLACK);
		PROCESS_VAL(PINK);
	}
#undef PROCESS_VAL
	return outs << c;
}

// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const Player& player)
{
	string separator = "---------------------------------------------------------------------------------\n";
	outs << separator << player.name + " has the following items: \n"
		<< player.elektro << " Elektros \n"
		<< player.houses.size() << " " << player.color << " colored Houses\n";

	return outs;
}


//int main()
//{
//
//	cout << "Hello and Welcome to Powergrid\n\n";
//
//	Player PL1 =  Player("Yassine", 50, RED);
//
//	PL1.grabhouses();
//
//	cout << PL1 << endl;
//
//	SummaryCards overviewCard = SummaryCards(PL1);
//	cout << overviewCard;
//
//	fstream outfile;
//	outfile.open("players.txt");
//
//	//write text into file
//	outfile << "ABCD.";//test
//	
//	//closing the file
//	outfile.close();
//
//	system("pause");
//	return 0;
//}


	Player PL1 =  Player("Yassine", 50, RED);

	PL1.grabhouses();

	cout << PL1 << endl;

	SummaryCards overviewCard = SummaryCards(PL1);
	cout << overviewCard;

	std::ofstream outfile("players.txt", std::ios_base::app);
	if (outfile.is_open()) {
		outfile << PL1;
		outfile << overviewCard;//test

		outfile.close();
	}
	else cout << "cannot open the file ";

	system("pause");
	return 0;
}

