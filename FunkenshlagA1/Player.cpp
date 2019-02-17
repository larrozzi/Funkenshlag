#include "Player.h"
#include <iostream>
#include <string>


using std::auto_ptr;

using std::string;
using std::cout;
using std::endl;
using std::cin;


Player::Player()
{
}

Player::Player(string name,  int elektro) : name{name}, elektro{elektro}
{
}

Player ::~Player()
{
}

inline string Player::getName() const {
	return name;
}

inline void Player::setName(string name) {
	this->name = name;
}

inline int Player::getElektro() const {
	return elektro;
}
inline void Player::setElektro(int elektro) {
	this->elektro = elektro;
}
//************** build houses in cities if possible *****************
bool Player::BuildHouse(CityNode& city, House& house) {
	int houseCost = city.getPrice();
	if (!city.unUse() ) //err :this should return bool
		return false;
	else {
		//elektro -= houseCost;
		setElektro(getElektro() - houseCost);
		houses.push_back(house); // add house on vector houses
		return true;
	}
}
// show powerplant in actual market and future market

//************** buy powerplants at auction *****************
bool Player::bidonPowerPlant(cardDeck& cardDeck, int position, int price) {
	if (position <= 3 & getElektro() >= price) {
		setElektro(getElektro() - price);
		if (myPowerPlants.size() < 3) {
			AddPowerPlant(cardDeck.GetPlant(position));
			cardDeck.RemovePlant(position);
			cardDeck.DrawPlant();
			return true;
		}
	}
	return false;
}



//vector <Resource> getRecources() {
//	 return resources;
 //}



 bool Player::AddPowerPlant(PowerPlantCards powerplant) {
	 if (myPowerPlants.size() == 3)
		 return false;
	 myPowerPlants.push_back(powerplant);
	 return true;

 }

 //void Player::ReplacePowerPlant(auto_ptr<PowerPlant> newplant, int toReplace) {
 //}

//int Player::getHighestPowerPlant() {
//	int max;
//	for (<PowerPlantCards> highestplant : powerplants) {
//		if (highestplant->getPrice() > max)
//			max = highestplant->getPrice();
//	}
//	return max;
//}
//


//********************** buy resources********************
bool Player::BuyResources(ResourceMarket& rMarket, PowerPlantCards& plant, Resource resource, int amount)
{
	int price = rMarket.getPrice(resource, amount);
	if (amount >= 0 && getElektro() > price &&
		(plant.getTotalPlacedResources() + amount) <= (2 * plant.getCapacity()) &&
		rMarket.resource.available()
		)
	{
		plant.placeResource(resource, amount);
		setElektro(getElektro() - price);
		rMarket.removeResource(resource, amount);
		return true;
	}
	return false;
}



void Player::OutputPlayerStatus() const {
	string separator = "---------------------------------------------------------------------------------\n";
	string PlayerStatus;
	string msg = separator + name +  " has" + to_string(getElektro()) + "Elektros" + "\n";

		//print powerplants 
	PlayerStatus += msg + " and owns the following Power plants: ";
	for (int i = 0; i < myPowerPlants.size(); i++)
		PlayerStatus += to_string(myPowerPlants[i].getCardValue() )+ ",";
	PlayerStatus += "\n";
			
	//print resources
	
	for (int i = 0; i < myPowerPlants.size(); i++)
		PlayerStatus +="Power plant number "+ to_string(myPowerPlants[i].getCardValue())+ "has" + myPowerPlants[i].presentresource();
	PlayerStatus += "\n";

		//print houses 
	PlayerStatus += "Here are the cities he controls: ";
	for (int i = 0; i < houses.size(); i++)
		PlayerStatus += houses[i].getName() + ",";
	PlayerStatus += "\n";

		// printing each PLayer**
	cout << PlayerStatus;
}

inline std::ostream& operator<<(std::ostream& stream, const Player& player) {
	stream << player.OutputPlayerStatus();
}
