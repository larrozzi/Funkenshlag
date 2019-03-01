#include "Player.h"
#include <iostream>
#include <string>

using std::auto_ptr;

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;

Player::Player()
{
}

Player::Player(string name, int elektro, HouseColor _color) : name{ name }, elektro{ elektro }, _color{ _color }{
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

inline void Player::setColor( HouseColor _color) {
	this->_color = _color;
}
inline HouseColor Player::getColor()const {
	return _color;
}

vector<House>Player::grabhouses()
{
	vector<House>houses;

	for (int i=0; i < 22; i++) {
		houses.push_back(HouseColor(_color));
	}
	return houses;
}

// overloading output stream operator
std::ostream& operator<<(std::ostream& outs, const Player& player)
{
	string separator = "---------------------------------------------------------------------------------\n";
	outs << separator << player.name + " has the following items: \n"
		<< player.elektro << " Elektros \n"
		<< player.houses.size() << " " << player._color << " colored Houses\n";

	return outs;
}
//void Player::OutputPlayerStatus() const {
//	string separator = "---------------------------------------------------------------------------------\n";
//	string msg = separator + getName() + " has the following items \n" + "\t"+ to_string(getElektro()) + " Elektros" + "\n";
//	string PlayerStatus = msg;
//	//print houses 
//
//	PlayerStatus += "\tHe owns "+ houses.size();
//	PlayerStatus += "houses of color " + getColor();
//
//	cout << PlayerStatus;
	

	// overloading output operator for the enum HouseColour
	std::ostream& operator<<(std::ostream& outs, const HouseColor& colour)
	{
		const char* c = 0;
#define PROCESS_VAL(p) case(p): c = #p; break;
		switch (colour) {
			PROCESS_VAL(BLUE);
			PROCESS_VAL(RED);
			PROCESS_VAL(GREEN);
			PROCESS_VAL(YELLOW);
			PROCESS_VAL(BLACK);
		}
#undef PROCESS_VAL
		return outs << c;
	}
	


int main()
{
	//Player player1= new Player(YL, "White", 50);

		//cout << player1;
	
	cout << "Hello and Welcome to Powergrid\n\n";

	Player* PL1 = new Player("Yassine", 50, BLUE);
	
	//PL1->OutputPlayerStatus();

	cout << PL1;

	system("pause");
	return 0;
}
