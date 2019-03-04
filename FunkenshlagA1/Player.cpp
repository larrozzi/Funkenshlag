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

inline string Player::getName() const {
	return name;
}
inline void Player::setName( string name) {
	this->name = name;
}

inline int Player::getElektro() const {
	return elektro;
}
inline void Player::setElektro( int elektro) {
	this->elektro = elektro;
}

inline void Player::setColor( HouseColor color) {
	this->color = color;
}
inline HouseColor Player::getColor()const {
	return color;
}

vector<House>Player::grabhouses()
{
	for (int i=0; i < 22; i++) {
		houses.push_back(House(color));
	}
	return houses;
}

// overloading output operator for the enum HouseColor
std::ostream& operator<<(std::ostream& outs, const HouseColor& color)
{
	const char* c = 0;
#define PROCESS_VAL(p) case(p): c = #p; break;
	switch (color) {
		PROCESS_VAL(RED);
		PROCESS_VAL(BLUE);
		PROCESS_VAL(GREEN);
		PROCESS_VAL(YELLOW);
		PROCESS_VAL(BLACK);
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


int main()
{

	cout << "Hello and Welcome to Powergrid\n\n";

	Player PL1 =  Player("Yassine", 50, RED);

	PL1.grabhouses();

	cout << PL1 << endl;

	SummaryCards overviewCard = SummaryCards(PL1);
	cout << overviewCard;

	fstream outfile;
	outfile.open("players.txt");

	//write text into file
	outfile << "ABCD.";//test
	
	//closing the file
	outfile.close();

	system("pause");
	return 0;
}

